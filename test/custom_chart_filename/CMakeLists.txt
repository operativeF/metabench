# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

# This test makes sure that we correctly name the JSON and HTML files
# containing the chart when the 'FILENAME' options is used in metabench_add_benchmark.

cmake_minimum_required(VERSION 3.1)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../..")
include(metabench)

metabench_add_dataset(dummy dummy.cpp.erb "[1, 2, 3]")
metabench_add_benchmark(check DATASETS dummy FILENAME a_custom_filename)

enable_testing()

add_test(NAME generate_the_charts
    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR} --target check)

add_test(NAME make_sure_we_generate_correctly_named_files
    COMMAND ${RUBY_EXECUTABLE}
        -e "json = '${CMAKE_CURRENT_BINARY_DIR}/a_custom_filename.json'"
        -e "html = '${CMAKE_CURRENT_BINARY_DIR}/a_custom_filename.html'"
        -e "raise \"file #{json} is missing\" if !File.exist?(json)"
        -e "raise \"file #{html} is missing\" if !File.exist?(html)"
)

set_tests_properties(make_sure_we_generate_correctly_named_files PROPERTIES DEPENDS generate_the_charts)
