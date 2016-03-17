# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(datasets)
foreach(dataset fusion.list fusion.vector hana.basic_tuple hana.tuple std.tuple)
    dependencies_are_satisfied(satisfied ${dataset})

    if (${satisfied})
        metabench_add_dataset(${dataset} ${dataset}.cpp.erb "(1..10)")
        list(APPEND datasets ${dataset})
    endif()
endforeach()

metabench_add_benchmark(benchmark.hetero.make DATASETS ${datasets})
