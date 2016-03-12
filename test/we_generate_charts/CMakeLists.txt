# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

# This test makes sure that we actually generate JSON and HTML files
# containing the charts.

cmake_minimum_required(VERSION 3.1)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../..")
include(metabench)

metabench_add_dataset(dummy benchmark/dummy.cpp.erb "[1, 2, 3]" "{}")
metabench_add_benchmark(check dummy)

enable_testing()

add_test(NAME generate_the_charts
    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR} --target check)

add_test(NAME make_sure_we_generate_charts
    COMMAND ${RUBY_EXECUTABLE}
        -e "json = '${CMAKE_CURRENT_BINARY_DIR}/check.json'"
        -e "html = '${CMAKE_CURRENT_BINARY_DIR}/check.html'"
        -e "raise \"file #{json} is missing\" if !File.exist?(json)"
        -e "raise \"file #{html} is missing\" if !File.exist?(html)"
)

set_tests_properties(make_sure_we_generate_charts PROPERTIES DEPENDS generate_the_charts)
