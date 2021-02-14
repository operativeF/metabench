#!/usr/bin/env python3

import argparse
from mako.template import Template
import os
import json
from progress.bar import ChargingBar
import multiprocessing
import re
from subprocess import PIPE
import platform
import time
import sys
import touch
import unittest
import psutil
import numpy as np
import matplotlib.pyplot as plt, mpld3

# TODO: Remove argparse, as we're just going to embed all of these functions into cmake
# or at least make it so that all of the files can be globally accessed in cmake.
parser = argparse.ArgumentParser(description="Called from CMake, takes build arguments to start Metabench and generate results.")
parser.add_argument("-bl", "--build_cmd", help="CMake generated build commands.", required=False)
parser.add_argument("-dl", "--cmake_bin_dir", help="CMake bin directory.", required=False)
parser.add_argument("-ml", "--metabench_dir", help="Metabench project directory.", required=False)
parser.add_argument("-xl", "--cmake_exe_suffix", help="Suffix for the executable generated by build process.", required=False)

args = vars(parser.parse_args())

CMAKE_CMD = args["build_cmd"]
CMAKE_BIN_DIR = args["cmake_bin_dir"]
METABENCH_DIR = args["metabench_dir"]
CMAKE_EXE_SUFFIX = args["cmake_exe_suffix"]

# TODO: Test precompiled headers for differences in compile time.
# Use a verbose output, header includes, and preprocessor output to determine
# the actual work involved with this process vs normal process. We want to eliminate
# as much of the parsing of non-template stuff in the front-end as possible.
def pch_build():
    pass

def memusg(command_line):
    if(platform.system() == "Linux"):
        def get_pgid(pgid): # TODO: Aliasing problem here?
            return "/bin/ps -o rss= -g " + pgid
    elif(platform.system() == "Windows"):
        def get_pgid(pgid):
            psutil.Popen(["Get-Process -Id", pgid, "| Select-Object WS"])
    else:
        SystemError("Invalid system: cannot determine platform for process info.")

    # TODO: Create separate process for memory consumption that won't rely on the parent process.
    # 
    memory_consumption = 0
    
    memory_inspect = multiprocessing.Process([command_line])
    memory_inspect.start()
    while memory_inspect.is_alive():
        memory_consumption = max([memory_consumption, get_pgid(memory_inspect.pid)])
        time.sleep(0.01)
    
    return memory_consumption

def build(target, comp_type):
    ### Check command code
    #command = CMAKE_CMD + " --build " + " . " + " --target " + target
    # TODO: Compile and link commands should be taken from cmake input
    comp_command = "clang-cl.exe " + "-m64 " + target + ".cpp" + " /c" + " /O2"
    link_command = "clang-cl.exe " + "-m64 " + target + ".obj"
    cpp_file = target + ".cpp"
    #exe_file = target + '.' + CMAKE_EXE_SUFFIX
    exe_file = target + '.' + "exe"
    #print(command)
    # Change the timestamp of the source file and remove the executable (if it exists) to
    # ensure that CMake considers the target as outdated.

    touch.touch(cpp_file)

    if os.path.exists(exe_file):
        os.remove(exe_file)

    comp_mem = 0

    t_compile_start = time.perf_counter_ns()
    # memusg(comp_command)
    memory_inspect = psutil.Popen(comp_command)
    memory_inspect.wait()

    t_compile_end = time.perf_counter_ns()

    link_mem = 0
    t_link_start = time.perf_counter_ns()
    link_output = psutil.Popen(link_command)
    link_output.wait()
        # if link_mem < link_output.memory_info().vms:
        #     link_mem = link_output.memory_info().vms
        #time.sleep(0.5) # TODO: Test this for accuracy
    t_link_end = time.perf_counter_ns()

    result = {}
    return (t_compile_end - t_compile_start) / 1e9

def memory_usage():
    pass

# The function compile is a custom command run by cmake to drive the actual
# compiler.
def compile_target(target):
    command_line = ['${PYTHON_EXECUTABLE}', ' ', '${MEMUSG_PY_PATH}'] + sys.argv
    t0 = time.perf_counter_ns()
    # TODO: Get the memory usage from this subprocess via psutil based Popen
    comp_cstdout, comp_stderr = psutil.Popen([command_line],stdout=PIPE,stderr=PIPE)
    t1 = time.perf_counter_ns()
    # TODO: Return stdout, stderr, status, compile options, and total time.
    print(t1 - t0)

def create_rendered_file(mako_template, cpp_target_file, type_iterations, metabench_flags=""):
    cpp_file = open(cpp_target_file, 'w')
    write_cpp_file = lambda cpp_code: cpp_file.write(cpp_code)
    temp_file = Template(filename=mako_template)
    code = temp_file.render(iterations=type_iterations)
    write_cpp_file(metabench_flags + code)
    cpp_file.close()

# TODO: To be deleted once all of the good stuff is taken out of this function.
def measure(target, mako_template, inrange, repetitions, steps):
    target_cpp_file = target + ".cpp"
    data = {}
    ### Time here   
    ### Setup the progress bar
    with ChargingBar("Processing", max=inrange) as bar:
        for n in range(0 + steps, inrange + steps, steps):
            compile = lambda comp_type: build(target, comp_type)
            ### Returns build target output
            create_rendered_file(mako_template, target_cpp_file, n)
            ### Baseline, built without #define METABENCH
            # TODO: Does this really need to be done each time? Probably not?
            base = sum([compile("Base") for rep in range(repetitions)]) / repetitions
            create_rendered_file(mako_template, target_cpp_file, n, "#define METABENCH\n")
            ### Build with #define METABENCH
            total = sum([compile("Measure") for rep in range(repetitions)]) / repetitions
            bar.next(steps)
            data.update({n: [base, total, total - base]}) ### Pipe data in
    bar.finish()
    #print(data.items())
    return data

def create_chart(datasets, aspect, title, subtitle, x_label, y_label, output_file):
    xpts = []
    ypts = []

    for key, data in datasets.items():
        xpts.append(key)
        ypts.append(data[2])

    plt.plot(xpts, ypts, label="New Label", marker='o')
    plt.title(title)
    plt.xlabel(x_label)
    plt.ylabel(y_label)
    plt.legend()
    # TODO: Implement interactive backend
    plt.savefig(output_file)

class time_per_elems:
    def __init__(self, elem_count, time_pt_s):
        self.elem_count = elem_count
        self.time_pt_s = time_pt_s
    elem_count = 0
    time_pt_s = 0

class library_dataset:
    def __init__(self, name, color, tpe_pts):
        self.name = name
        self.color = color
        for elem_pt in tpe_pts:
            self.elem_pts.append(elem_pt)
    
    def set_time_pts(self, tpe_pts):
        for time_pt in tpe_pts:
            self.time_pts.append(time_pt)
    name = ""
    color = ""
    time_pts = []
    elem_pts = []

class lib_comparison_chart:
    libs_in_test = ""

    def __init__(self, val):
        self.val = val

def measure_library_datasets(library_mako_files, inrange, repetitions, steps):
    datasets = {}
    for file in library_mako_files:
        datasets += measure(file, file, inrange, inrange, repetitions, steps)

    return datasets

#measure("test", "generate_test.cpp.mako", 500, 10, 100)
measurements = measure("test", "homemade_test.cpp.mako", 200, 5, 50)
create_chart(measurements, aspect=None, title="homemade", subtitle="", x_label="Number of Elements", y_label="Time (in seconds)", output_file="test")