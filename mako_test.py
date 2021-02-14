#!/usr/bin/env python3

from mako.template import Template
import os
import timeit
import json
from progress.bar import Bar
import re
import subprocess
import touch
import unittest

def gen_templates(mako_template, ns):
    for j in range(ns):
        mytemp = Template(filename=mako_template)   
        f = open('generated_template.cpp', 'w')
        rendered_file = mytemp.render(i=j)
        f.write(rendered_file)
        print(rendered_file)
        f.close()
        print('\n') ### only works on output to console

def render(mako_template, n):
    try:
        temp_file = Template(filename=mako_template)
    except IOError:
        print("Error: Cannot find file or read data.")
    ### Return / pipe the rendered file here?
    rendered_file = temp_file.render(i=n)
    print(rendered_file)



def build(target):
    ### Check command code
    command = ['${CMAKE_COMMAND}', '--build', '${CMAKE_BINARY_DIR}', '--target', target]
    cpp_file = ['${METABENCH_DIR}'/{target}.cpp]
    exe_file = ['${METABENCH_DIR}' + '/{target}' + '${CMAKE_EXECUTABLE_SUFFIX}']

    """
    Change the timestamp of the source file and remove the executable (if it exists) to
    ensure that CMake considers the target as outdated.
    """

    touch.touch(cpp_file)
    if os.path.exists(exe_file):
        os.remove(exe_file)

    output = subprocess.check_output(command,universal_newlines=True,check=True,stderr=subprocess.STDOUT)    

    compile_cli = re.match(('/\\[compilation command: (.+)\\]/i'), output)
    link_cli = re.match('/\\[link command: (.+)\\]/i', output)

    ###python -mtimeit -c "exec(\"import subprocess\nimport timeit\ns = subprocess.check_output(['cl.exe','test.cpp', '/EHsc'], shell=True, universal_newlines=True)\nprint(str(s))\")"

# Return an array of measurements representing the compilation of a mako template
# for the values of 'n' in the specified 'inrange' for 'repetitions' number of times.
def measure(target, mako_template, inrange, repetitions, METABENCH_DIR):
    cpp_file = METABENCH_DIR + target + ".cpp"
    data = {}
    lrange = range(inrange)
    cpp_file_write = open(cpp_file, 'w')
    ### Time here   
    ### Setup the progress bar

    for n in lrange:
        write_cpp_file = lambda code: cpp_file_write.write(code)
        compile = [build(target) for reps in range(repetitions)]
        ### Returns build target output
        temp_file = Template(filename=mako_template)
        code = temp_file.render(i=n)
        base = compile() ### Baseline, built without #define METABENCH
        write_cpp_file('#define METABENCH\n' + code)
        total = compile() ### Build with #define Metabench
        data.update({'n': n, 'base': base, 'total': total}) ### Pipe data in
    return data

#measure("test", 'generate_test.cpp.mako', 4, 1, "C:/dev/metabench/")
gen_templates('generate_test.cpp.mako', 4)