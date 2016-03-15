# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.1)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/..")

include(metabench)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

metabench_add_dataset(std_tuple make_tuple/std_tuple.cpp.erb "(0...50).step(5)")
metabench_add_dataset(recursive_tuple make_tuple/recursive_tuple.cpp.erb "(0...50).step(5)")
metabench_add_benchmark(make_tuple DATASETS std_tuple recursive_tuple CHART make_tuple/chart.json)

metabench_add_dataset(std_decay decay/std_decay.cpp.erb "(0...500).step(100)")
metabench_add_dataset(my_decay decay/my_decay.cpp.erb "(0...500).step(100)")
metabench_add_benchmark(decay DATASETS std_decay my_decay CHART decay/chart.json)

add_custom_target(benchmarks ALL DEPENDS decay make_tuple)
