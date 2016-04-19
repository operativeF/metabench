# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.1)

project(Metabench CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
include(metabench)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

metabench_add_dataset(example.std_decay example/decay/std_decay.cpp.erb "(0...500).step(100)" NAME std::decay)
metabench_add_dataset(example.my_decay example/decay/my_decay.cpp.erb "(0...500).step(100)" NAME "my decay")

add_custom_target(should_trigger_the_bug
    COMMAND "echo"
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/example.std_decay.json
            ${CMAKE_CURRENT_BINARY_DIR}/example.my_decay.json
    USES_TERMINAL)

