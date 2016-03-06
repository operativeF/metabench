# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

# This test makes sure that Metabench sets up a Ctest target for testing the
# benchmark when testing is enabled.

enable_testing()
add_benchmark(test.ctest_target "benchmark")
add_dependencies(check test.ctest_target)
