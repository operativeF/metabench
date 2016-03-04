# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.0)

find_package(Ruby 2.1)
if(NOT ${RUBY_FOUND})
    message(WARNING "Ruby >= 2.1 was not found; the metabench.cmake module can't be used.")
    return()
endif()

execute_process(COMMAND ${RUBY_EXECUTABLE} -r ruby-progressbar -r tilt -e ""
                RESULT_VARIABLE __MISSING_GEMS
                OUTPUT_QUIET ERROR_QUIET)
if(${__MISSING_GEMS})
    message(WARNING
        "The 'ruby-progressbar' and/or 'tilt' gems were not found; "
        "the metabench.cmake module can't be used."
        "Use `gem install ruby-progressbar tilt` to install the missing gems.")
    return()
endif()


# The base unit of this CMake module is a directory with the following layout:
#   chart.json
#   file1.cpp
#   ...
#   fileN.cpp
#
# Given a target name and a directory with relative path from CMake's current
# source directory (let's say `path/to/dir`), `add_benchmark(target "path/to/dir")`
# creates a new target with the specified name, which, when run, creates a
# `path/to/dir.json` file in CMake's curent binary directory. This file is the
# result of evaluating `path/to/dir/chart.json` as an ERB template. In addition,
# note that `path/to/dir/chart.json` is passed through CMake `configure_file`
# prior to being evaluated as an ERB template. This can be used to include
# platform-dependent informations in the `chart.json` file.
function(add_benchmark target path_to_dir)
    # Dependencies of the benchmark; the benchmark will be considered
    # outdated when any of these is changed.
    file(GLOB dependencies ${path_to_dir}/chart.json
                           ${path_to_dir}/*.cpp
                           ${path_to_dir}/*.hpp)

    # We first pass the chart.json file through CMake's `configure_file`.
    set(configured_chart_json "${CMAKE_CURRENT_BINARY_DIR}/_metabench/${path_to_dir}/chart.json")
    configure_file("${path_to_dir}/chart.json" ${configured_chart_json} @ONLY)

    add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.json"
        COMMAND ${RUBY_EXECUTABLE} -r fileutils -r tilt/erb -r ${CMAKE_CURRENT_BINARY_DIR}/metabench.rb
            # We use `.render(binding)` to carry the 'require' of the 'metabench.rb' module.
            -e "chart = Tilt::ERBTemplate.new('${configured_chart_json}').render(binding)"
            -e "FileUtils.mkdir_p(File.dirname('${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.json'))"
            -e "File.open('${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.json', 'w') { |f| f.write(chart) }"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${path_to_dir}
        DEPENDS ${dependencies}
        VERBATIM USES_TERMINAL
        COMMENT "Generating benchmark for ${path_to_dir}")

    add_custom_target(${target}
        DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.json")
endfunction()


# The following is the `metabench.rb` Ruby module, which is automatically
# 'require'd in the `chart.json` file. This module defines the methods
# that are used to process and run the compiler on the `.cpp` files of a
# benchmark directory. This is hardcoded here so that users only have to
# copy the `metabench.cmake` module to their project, without worrying
# about implementation details.

set(METABENCH_RB
"require 'benchmark'                                                                               \n"
"require 'open3'                                                                                   \n"
"require 'pathname'                                                                                \n"
"require 'ruby-progressbar'                                                                        \n"
"require 'tempfile'                                                                                \n"
"require 'tilt/erb'                                                                                \n"
"                                                                                                  \n"
"                                                                                                  \n"
"# This function is meant to be called inside a ERB-based `chart.json` file.                       \n"
"# `erb_template` should be the name of the `.cpp` file containing the                             \n"
"# benchmark to run.                                                                               \n"
"def measure(erb_template, range, cxx: ENV['CXX'], cxxflags: ENV['CXXFLAGS'], env: {})             \n"
"  raise \"invalid `cxx` parameter (#{cxx})\" if not cxx                                           \n"
"  range = range.to_a                                                                              \n"
"                                                                                                  \n"
"  # if ENV['BOOST_HANA_JUST_CHECK_BENCHMARKS'] && range.length >= 2                               \n"
"  #   range = [range[0], range[-1]]                                                               \n"
"  # end                                                                                           \n"
"                                                                                                  \n"
"  progress = ProgressBar.create(format: '%p%% %t | %B |', title: erb_template,                    \n"
"                                total: range.size,        output: STDERR)                         \n"
"  range.each do |n|                                                                               \n"
"    # Evaluate the ERB template with the given environment, and save the                          \n"
"    # result in a temporary file.                                                                 \n"
"    code = Tilt::ERBTemplate.new(erb_template).render(nil, n: n, env: env)                        \n"
"    Tempfile.create(['tmp', '.cpp'], Dir.pwd) do |cpp_file|                                       \n"
"      begin                                                                                       \n"
"        # We create exe_file and close it explicitly because if the compilation                   \n"
"        # fails and the exe_file is deleted by the compiler, we'll raise an                       \n"
"        # error but Tempfile.create will re-raise an error while trying to                        \n"
"        # remove the nonexistent file.                                                            \n"
"        exe_file = Tempfile.new(['tmp', '.o'], Dir.pwd)                                           \n"
"        cpp_file.write(code) && cpp_file.flush                                                    \n"
"        data = {n: n}                                                                             \n"
"                                                                                                  \n"
"        # Compile the file and gather timing statistics. The timing statistics                    \n"
"        # are output to stdout when we compile the file.                                          \n"
"        data[:time] = Benchmark.realtime {                                                        \n"
"          command = \"#{cxx} #{cxxflags} -o #{exe_file.path} #{cpp_file.path}\"                   \n"
"          stdout, stderr, status = Open3.capture3(command)                                        \n"
"                                                                                                  \n"
"          error_string = <<-EOS                                                                   \n"
"compilation error: #{command}                                                                     \n"
"                                                                                                  \n"
"stdout                                                                                            \n"
"#{'-'*80}                                                                                         \n"
"#{stdout}                                                                                         \n"
"                                                                                                  \n"
"stderr                                                                                            \n"
"#{'-'*80}                                                                                         \n"
"#{stderr}                                                                                         \n"
"                                                                                                  \n"
"code                                                                                              \n"
"#{'-'*80}                                                                                         \n"
"#{code}                                                                                           \n"
"EOS\n"
"          raise error_string if not status.success?                                               \n"
"        }                                                                                         \n"
"                                                                                                  \n"
"        # Size of the generated executable in KB                                                  \n"
"        data[:size] = exe_file.size.to_f / 1000                                                   \n"
"                                                                                                  \n"
"        progress.increment                                                                        \n"
"        yield data                                                                                \n"
"                                                                                                  \n"
"      ensure                                                                                      \n"
"        exe_file.close!                                                                           \n"
"      end                                                                                         \n"
"    end                                                                                           \n"
"  end                                                                                             \n"
"ensure                                                                                            \n"
"  progress.finish if progress                                                                     \n"
"end                                                                                               \n"
"                                                                                                  \n"
"def measure_compile_time(relative_path_to_erb_template, range, **options)                         \n"
"  result = []                                                                                     \n"
"  measure(relative_path_to_erb_template, range, **options) do |data|                              \n"
"    result << [data[:n], data[:time]]                                                             \n"
"  end                                                                                             \n"
"  return result                                                                                   \n"
"end                                                                                               \n"
"                                                                                                  \n"
"def measure_exe_size(relative_path_to_erb_template, range, **options)                             \n"
"  result = []                                                                                     \n"
"  measure(relative_path_to_erb_template, range, **options) do |data|                              \n"
"    result << [data[:n], data[:size]]                                                             \n"
"  end                                                                                             \n"
"  return result                                                                                   \n"
"end                                                                                               \n"
)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/metabench.rb ${METABENCH_RB})
