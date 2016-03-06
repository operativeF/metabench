# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

# This test makes sure that Metabench sets up a Ctest target for testing the
# benchmark when testing is enabled.

cmake_minimum_required(VERSION 3.0)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../..")

enable_testing()
include(metabench)
add_benchmark(check "benchmark")
