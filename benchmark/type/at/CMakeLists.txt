# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(datasets)
foreach(dataset brigand.list meta.list metal.list mpl.list mpl.vector)
    dependencies_are_satisfied(satisfied ${dataset})

    if (${satisfied})
        metabench_add_dataset(dataset.type.at.${dataset} ${dataset}.cpp.erb "(1..20).step(2)")
        list(APPEND datasets dataset.type.at.${dataset})
    endif()
endforeach()

metabench_add_benchmark(benchmark.type.at DATASETS ${datasets})
