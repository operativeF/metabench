# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(datasets)
foreach(dataset hana.types mpl.list mpl.vector)
    dependencies_are_satisfied(satisfied ${dataset})

    if (${dataset} MATCHES "mpl\\.")
        set(env "(1..20).step(2)")
    else()
        set(env "(1..500).step(10)")
    endif()

    if (${satisfied})
        metabench_add_dataset(dataset.type.transform.${dataset} ${dataset}.cpp.erb ${env})
        list(APPEND datasets dataset.type.transform.${dataset})
    endif()
endforeach()

metabench_add_benchmark(benchmark.type.transform DATASETS ${datasets})
add_dependencies(benchmarks benchmark.type.transform)
