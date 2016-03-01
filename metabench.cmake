# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

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
# Given a directory with relative path from CMake's current source directory
# (let's say `path/to/dir`), `add_benchmark("path/to/dir")` creates a new
# target named `path.to.dir`. When this target is run, a `path/to/dir.json`
# file is created in CMake's curent binary directory. This file contains ?????.

# TODO: allow configuring the chart.json file through CMake
# TODO: allow support.rb to be included seemlessly by the user.
#       support.rb shouldn't have to be placed at some specific place.
# TODO: how to pass CXX and CXXFLAGS to the script that runs the compiler?
# TODO: For some reason, the File.open call below fails on the Makefile
#       generator, because the directory can't be found. It works on Ninja,
#       though.
function(add_benchmark path_to_dir)
    # Dependencies of the benchmark; the benchmark will be considered
    # outdated when any of these is changed.
    file(GLOB dependencies ${path_to_dir}/chart.json
                           ${path_to_dir}/*.cpp
                           ${path_to_dir}/*.hpp)

    add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.json"
        COMMAND ${RUBY_EXECUTABLE} -r tilt/erb -r ${CMAKE_SOURCE_DIR}/../metabench.rb
            # We use `.render(binding)` to carry the 'require' of the 'metabench.rb' module.
            -e "chart = Tilt::ERBTemplate.new('chart.json').render(binding)"
            -e "File.open('${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.json', 'w') { |f| f.write(chart) }"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${path_to_dir}
        DEPENDS ${dependencies}
        VERBATIM USES_TERMINAL
        COMMENT "Generating benchmark for ${path_to_dir}")

    string(REGEX REPLACE "/" "." target_name ${path_to_dir})
    add_custom_target(${target_name}
        DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${path_to_dir}.json")
endfunction()
