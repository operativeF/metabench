# Copyright Louis Dionne 2017
# Copyright Thomas Figueroa 2019 - 2021
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.1)

project(Metabench CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Python3 REQUIRED COMPONENTS Interpreter NumPy)

include_directories(dependencies)
add_subdirectory(benchmark)

# set_target_properties(test PROPERTIES
#     RULE_LAUNCH_COMPILE "${PYTHON_EXECUTABLE} -- \"${COMPILE_PY_PATH}\""
#     RULE_LAUNCH_LINK "${PYTHON_EXECUTABLE} -- \"${LINK_PY_PATH}\""
#     #RUNTIME_OUTPUT_DIRECTORY "${METABENCH_DIR}"
#     #METABENCH_DATASET_PATH "${ARGS_OUTPUT}"
# ) 

#enable_testing()

#add_subdirectory(benchmark)
#add_subdirectory(example)
#add_subdirectory(test)
