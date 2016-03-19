# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(datasets)
foreach(dataset fusion.list fusion.vector hana.basic_tuple hana.tuple std.tuple)
    dependencies_are_satisfied(satisfied ${dataset})

    if (${dataset} MATCHES "fusion\\.")
        set(env "(1..50).step(2)")
    elseif(${dataset} MATCHES "std\\.")
        set(env "(1..100).step(10)")
    else()
        set(env "(1..500).step(10)")
    endif()

    if (${satisfied})
        metabench_add_dataset(dataset.hetero.at.${dataset} ${dataset}.cpp.erb ${env})
        list(APPEND datasets dataset.hetero.at.${dataset})
    endif()
endforeach()

metabench_add_benchmark(benchmark.hetero.at DATASETS ${datasets})
add_dependencies(benchmarks benchmark.hetero.at)
