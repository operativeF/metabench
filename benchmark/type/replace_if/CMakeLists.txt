# Copyright Bruno Dutra 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set(datasets)
add_dataset(datasets dataset.type.replace_if.brigand.list  brigand.list.cpp.erb "(0..500).step(10)")
add_dataset(datasets dataset.type.replace_if.hana.types    hana.types.cpp.erb   "(0..500).step(10)")
add_dataset(datasets dataset.type.replace_if.meta.list     meta.list.cpp.erb    "(0..500).step(10)")
add_dataset(datasets dataset.type.replace_if.metal.list    metal.list.cpp.erb   "(0..500).step(10)")
add_dataset(datasets dataset.type.replace_if.mpl.list      mpl.list.cpp.erb     "(0..50).step(1)")
add_dataset(datasets dataset.type.replace_if.mpl.vector    mpl.vector.cpp.erb   "(0..50).step(1)")

metabench_add_benchmark(benchmark.type.replace_if DATASETS ${datasets} OUTPUT index.html)
add_dependencies(benchmarks benchmark.type.replace_if)
