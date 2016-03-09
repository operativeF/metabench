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


# metabench_add_benchmark(target path_to_dir)
#
#   Creates a target for running a compile-time benchmark. After issuing this
#   command, running the target named `target` will cause the benchmark in the
#   `path_to_dir` directory to be executed. For simplicity, let's denote by
#   `path/to/dir` the value of `path_to_dir` as a relative path from the current
#   source directory. Then, running the `target` target will create two files
#   in CMake's current binary directory, one named `path/to/dir.json` and the
#   other named `path/to/dir.html`. `path/to/dir.json` will contain the result
#   of rendering the `chart.json` file in the original benchmark folder as an
#   ERB template, while `path/to/dir.html` will contain the minimal code for
#   visualizing the content of the JSON file as a [Highchart][1] chart.
#
#   In addition, prior to being rendered as an ERB template, the `chart.json`
#   file will be passed through CMake's `configure_file` function. This can be
#   used to include platform-dependent informations in the `chart.json` file.
#
#   Finally, a CTest target with the same name is also created. When run, this
#   CTest target will run the benchmark for only a subset of the possible input
#   values, and won't gather any benchmarking data. This is very useful to make
#   sure that benchmarks stay sane as part of continuous integration scripts,
#   for example.
#
#   Parameters
#   ----------
#   target:
#       The name of the target associated to this benchmark.
#
#   path_to_dir:
#       The path of the benchmark to run. This may be either an absolute path
#       or a path relative to the current source directory. The exact structure
#       expected for this directory is documented in the official documentation
#       of this module at https://github.com/ldionne/metabench.
#
# [1]: http://www.highcharts.com
function(metabench_add_benchmark target path_to_dir)
    # Transform any absolute path to a relative path from the current source directory.
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" path_to_dir ${path_to_dir})

    # Sanity checks on the arguments
    if (NOT IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${path_to_dir})
        message(FATAL_ERROR "Path specified to add_benchmark (${path_to_dir}) is not a valid directory.")
    endif()

    if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${path_to_dir}/chart.json)
        message(FATAL_ERROR "Path specified to add_benchmark (${path_to_dir}) does not contain a chart.json file.")
    endif()

    # Create a dummy executable that will be used to run the benchmark. We'll
    # run the benchmark through CMake, which allows us to be cross-platform
    # without additional work.
    file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/_metabench/${path_to_dir}/measure.cpp "")
    add_executable(_metabench.${target} EXCLUDE_FROM_ALL ${CMAKE_CURRENT_BINARY_DIR}/_metabench/${path_to_dir}/measure.cpp)
    set_target_properties(_metabench.${target} PROPERTIES RULE_LAUNCH_COMPILE "${RUBY_EXECUTABLE} -- ${MEASURE_RB_PATH}")
    target_include_directories(_metabench.${target} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/${path_to_dir}")

    # Dependencies of the benchmark; the benchmark will be considered
    # outdated when any of these is changed.
    file(GLOB dependencies "${CMAKE_CURRENT_SOURCE_DIR}/${path_to_dir}/*")

    # We pass the chart.json file through CMake's `configure_file`.
    set(configured_chart_json "${CMAKE_CURRENT_BINARY_DIR}/_metabench/${path_to_dir}/chart.json")
    configure_file("${path_to_dir}/chart.json" ${configured_chart_json} @ONLY)

    # We pass metabench.rb file through CMake's `configure_file`, so current
    # values of CMAKE_CXX_COMPILER and CMAKE_CXX_FLAGS are taken into account.
    set(configured_metabench_rb "${CMAKE_CURRENT_BINARY_DIR}/_metabench/${path_to_dir}/metabench.rb")
    configure_file(${METABENCH_RB_PATH} ${configured_metabench_rb} @ONLY)

    # Setup the command to generate `path/to/dir/chart.json`.
    add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.json"
        COMMAND ${RUBY_EXECUTABLE} -r fileutils -r tilt/erb -r ${configured_metabench_rb}
            # We use `.render(binding)` to carry the 'require' of the 'metabench.rb' module.
            -e "chart = Tilt::ERBTemplate.new('${configured_chart_json}').render(binding)"
            -e "FileUtils.mkdir_p(File.dirname('${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.json'))"
            -e "IO.write('${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.json', chart)"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${path_to_dir}
        DEPENDS ${dependencies}
        VERBATIM USES_TERMINAL)

    # Setup the command to generate `path/to/dir/index.html`.
    add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.html"
        COMMAND ${RUBY_EXECUTABLE} -r tilt/erb
            -e "chart = IO.read('${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.json')"
            -e "index = Tilt::ERBTemplate.new('${CHART_TEMPLATE_HTML_PATH}').render(nil, {data: chart})"
            -e "IO.write('${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.html', index)"
        DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.json"
        VERBATIM)

    # Setup the command to test the benchmark.
    add_test(NAME ${target}
        COMMAND ${CMAKE_COMMAND} -E env METABENCH_TEST_ONLY=true
                ${RUBY_EXECUTABLE} -r tilt/erb -r ${configured_metabench_rb}
                -e "Tilt::ERBTemplate.new('${configured_chart_json}').render(binding)"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${path_to_dir})

    add_custom_target(${target}
        DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.json"
                "${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.html")
endfunction()


##############################################################################
# Below this line are scripts and other files that are required by one part or
# another of Metabench. They are hardcoded here so that users only have to
# copy the `metabench.cmake` module to their project, without having to worry
# about dependencies and other implementation details.
##############################################################################


##############################################################################
# metabench.rb
#
# The following is the `metabench.rb` Ruby module, which is automatically
# 'require'd in the `chart.json` file. This module defines the methods
# that are used to process and run the compiler on the `.cpp` files of a
# benchmark directory.
##############################################################################
set(METABENCH_RB_PATH ${CMAKE_CURRENT_BINARY_DIR}/_metabench/metabench.rb.in)
file(WRITE ${METABENCH_RB_PATH}
"require 'benchmark'                                                                                    \n"
"require 'open3'                                                                                        \n"
"require 'pathname'                                                                                     \n"
"require 'ruby-progressbar'                                                                             \n"
"require 'tempfile'                                                                                     \n"
"require 'tilt/erb'                                                                                     \n"
"                                                                                                       \n"
"                                                                                                       \n"
"module Metabench                                                                                       \n"
"  # This function is meant to be called inside a ERB-based `chart.json` file.                          \n"
"  # `erb_template` should be the name of the `.cpp` file containing the                                \n"
"  # benchmark to run.                                                                                  \n"
"  def self.measure(erb_template, range, env: {})                                                       \n"
"    measure_file = Pathname.new('\@CMAKE_CURRENT_BINARY_DIR\@/_metabench/\@path_to_dir\@/measure.cpp') \n"
"    exe_file = Pathname.new('\@CMAKE_CURRENT_BINARY_DIR\@/_metabench.\@target\@')                      \n"
"    command = '\@CMAKE_COMMAND\@ --build \@CMAKE_BINARY_DIR\@ --target _metabench.\@target\@'          \n"
"    range = range.to_a                                                                                 \n"
"    range = [range[0], range[-1]] if ENV['METABENCH_TEST_ONLY'] && range.length >= 2                   \n"
"                                                                                                       \n"
"    progress = ProgressBar.create(format: '%p%% %t | %B |', title: erb_template,                       \n"
"                                  total: range.size,        output: STDERR)                            \n"
"    range.each do |n|                                                                                  \n"
"      # Evaluate the ERB template with the given environment, and save the                             \n"
"      # result in a temporary file.                                                                    \n"
"      code = Tilt::ERBTemplate.new(erb_template).render(nil, n: n, env: env)                           \n"
"      measure_file.write(code)                                                                         \n"
"      data = {n: n}                                                                                    \n"
"                                                                                                       \n"
"      # Compile the file and get timing statistics. The timing statistics                              \n"
"      # are output to stdout when we compile the file, because we use the                              \n"
"      # `measure.rb` script below to launch the compiler with CMake.                                   \n"
"      stdout, stderr, status = Open3.capture3(command)                                                 \n"
"      command_line = stdout.match(/\\[command line: (.+)\\]/i)                                         \n"
"                                                                                                       \n"
"      # If we didn't match anything, that's because we went too fast, CMake                            \n"
"      # did not have the time to see the changes to the measure file and                               \n"
"      # the target was not rebuilt. So we sleep for a bit and then retry                               \n"
"      # this iteration.                                                                                \n"
"      (sleep 0.2; redo) if command_line.nil?                                                           \n"
"      error_string = <<-EOS                                                                            \n"
"compilation error: #{command_line.captures[0]}                                                         \n"
"                                                                                                       \n"
"stdout                                                                                                 \n"
"#{'-'*80}                                                                                              \n"
"#{stdout}                                                                                              \n"
"                                                                                                       \n"
"stderr                                                                                                 \n"
"#{'-'*80}                                                                                              \n"
"#{stderr}                                                                                              \n"
"                                                                                                       \n"
"code                                                                                                   \n"
"#{'-'*80}                                                                                              \n"
"#{code}                                                                                                \n"
"EOS\n"
"      raise error_string if not status.success?                                                        \n"
"      data[:time] = stdout.match(/\\[compilation time: (.+)\\]/i).captures[0].to_f                     \n"
"      # Size of the generated executable in KB                                                         \n"
"      data[:size] = File.size(exe_file).to_f / 1000                                                    \n"
"                                                                                                       \n"
"      progress.increment                                                                               \n"
"      yield data                                                                                       \n"
"    end                                                                                                \n"
"  ensure                                                                                               \n"
"    measure_file.write('')                                                                             \n"
"    progress.finish if progress                                                                        \n"
"  end                                                                                                  \n"
"                                                                                                       \n"
"  def self.compile_time(relative_path_to_erb_template, range, **options)                               \n"
"    result = []                                                                                        \n"
"    measure(relative_path_to_erb_template, range, **options) do |data|                                 \n"
"      result << [data[:n], data[:time]]                                                                \n"
"    end                                                                                                \n"
"    return result                                                                                      \n"
"  end                                                                                                  \n"
"                                                                                                       \n"
"  def self.executable_size(relative_path_to_erb_template, range, **options)                            \n"
"    result = []                                                                                        \n"
"    measure(relative_path_to_erb_template, range, **options) do |data|                                 \n"
"      result << [data[:n], data[:size]]                                                                \n"
"    end                                                                                                \n"
"    return result                                                                                      \n"
"  end                                                                                                  \n"
"end                                                                                                    \n"
)
##############################################################################
# end metabench.rb
##############################################################################

##############################################################################
# measure.rb
#
# This script is used to launch the compiler and measure the compilation time.
##############################################################################
set(MEASURE_RB_PATH ${CMAKE_CURRENT_BINARY_DIR}/_metabench/measure.rb)
file(WRITE ${MEASURE_RB_PATH}
"require 'benchmark'                                                    \n"
"command = ARGV.join(' ')                                               \n"
"time = Benchmark.realtime { `#{command}` }                             \n"
"puts \"[command line: #{command}]\"                                    \n"
"puts \"[compilation time: #{time}]\"                                   \n"
)
##############################################################################
# end measure.rb
##############################################################################

##############################################################################
# path/to/dir.html template
#
# The following is a template for the HTML files used to visualize the
# benchmarks. The template is completed by filling it with the contents
# of the corresponding JSON file.
#
# We also try to pre-download the `highcharts.js` library so that connectivity
# is only required when running the CMake configuration step, but not
# for visualizing the benchmarks thereafter. We hardcode the content of
# `highcharts.js` in the file so that the generated HTML file is self-
# standing, which can be useful for sharing benchmarks with others.
##############################################################################
set(CHART_TEMPLATE_HTML_PATH ${CMAKE_CURRENT_BINARY_DIR}/_metabench/chart_template.html)
set(HIGHCHARTS_JS_PATH ${CMAKE_CURRENT_BINARY_DIR}/_metabench/highcharts.js)
set(HIGHCHARTS_JS_URL "https://code.highcharts.com/highcharts.js")
file(DOWNLOAD ${HIGHCHARTS_JS_URL} ${HIGHCHARTS_JS_PATH})
file(READ ${HIGHCHARTS_JS_PATH} HIGHCHARTS_JS)
if ("${HIGHCHARTS_JS}" STREQUAL "")
    message(WARNING
        "metabench.cmake: The download of a JavaScript library for chart "
        "visualization failed. The library will be required by each HTML "
        "chart instead, so connectivity will be required to view these.")
    set(HIGHCHARTS_JS "<script src='${HIGHCHARTS_JS_URL}'></script>")
else()
    set(HIGHCHARTS_JS "<script type='text/javascript'>${HIGHCHARTS_JS}</script>")
endif()
file(WRITE ${CHART_TEMPLATE_HTML_PATH}
"<!DOCTYPE html>                                                                                    \n"
"<html>                                                                                             \n"
"<head>                                                                                             \n"
"  ${HIGHCHARTS_JS}                                                                                 \n"
"</head>                                                                                            \n"
"<body>                                                                                             \n"
"  <div id='container'><%= data %></div>                                                            \n"
"  <script type='text/javascript'>                                                                  \n"
"    (function () {                                                                                 \n"
"      var container = document.getElementById('container');                                        \n"
"      var options = JSON.parse(container.innerHTML);                                               \n"
"                                                                                                   \n"
"      // Set different default options                                                             \n"
"      options.chart = options.chart || { zoomType: 'xy' };                                         \n"
"      options.chart.renderTo = container;                                                          \n"
"                                                                                                   \n"
"      options.plotOptions = options.plotOptions || {};                                             \n"
"      options.plotOptions.series = options.plotOptions.series || {};                               \n"
"      options.plotOptions.series.marker = options.plotOptions.series.marker || { enabled: false }; \n"
"                                                                                                   \n"
"      if (options.series.stickyTracking == undefined) {                                            \n"
"        options.series.stickyTracking = false;                                                     \n"
"      }                                                                                            \n"
"                                                                                                   \n"
"      if (options.legend == undefined) {                                                           \n"
"        options.legend = {                                                                         \n"
"          layout: 'vertical',                                                                      \n"
"          align: 'right',                                                                          \n"
"          verticalAlign: 'middle',                                                                 \n"
"          borderWidth: 0                                                                           \n"
"        };                                                                                         \n"
"      }                                                                                            \n"
"                                                                                                   \n"
"      window.chart = new Highcharts.Chart(options);                                                \n"
"    })();                                                                                          \n"
"  </script>                                                                                        \n"
"</body>                                                                                            \n"
"</html>                                                                                            \n"
)
##############################################################################
# end index.html
##############################################################################
