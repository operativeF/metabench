#!/usr/bin/env bash
#
# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set -ev

if [[ "${CMAKE_GENERATOR}" == "" ]]; then CMAKE_GENERATOR=Ninja; fi

# Run the example
(rm -rf example/build && mkdir example/build && cd example/build && cmake .. -G"${CMAKE_GENERATOR}")
cmake --build example/build --target path.to.benchmark

# Run the unit tests
for dir in test/absolute_paths test/ctest_target test/env test/local_header test/n; do
  rm -rf ${dir}/build
  mkdir ${dir}/build
  (cd ${dir}/build && cmake .. -G"${CMAKE_GENERATOR}")
  cmake --build ${dir}/build --target check
  (cd ${dir}/build && ctest --output-on-failure)
done
