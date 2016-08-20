# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set(datasets)
add_dataset(datasets dataset.hetero.make.fusion.list      fusion.list.cpp.erb         "(0..50).step(10).to_a + [100, 200]")
add_dataset(datasets dataset.hetero.make.fusion.map       fusion.map.cpp.erb          "(0..50).step(10).to_a + [100, 200]")
add_dataset(datasets dataset.hetero.make.fusion.set       fusion.set.cpp.erb          "(0..50).step(10).to_a + [100, 200]")
add_dataset(datasets dataset.hetero.make.fusion.vector    fusion.vector.cpp.erb       "(0..50).step(10).to_a + [100, 200]")
add_dataset(datasets dataset.hetero.make.hana.basic_tuple hana.basic_tuple.cpp.erb    "(0..50).step(10).to_a + (100..500).step(100).to_a")
add_dataset(datasets dataset.hetero.make.hana.map         hana.map.cpp.erb            "(0..50).step(10).to_a + (100..500).step(100).to_a")
add_dataset(datasets dataset.hetero.make.hana.set         hana.set.cpp.erb            "(0..50).step(10).to_a + (100..500).step(100).to_a")
add_dataset(datasets dataset.hetero.make.hana.tuple       hana.tuple.cpp.erb          "(0..50).step(10).to_a + (100..500).step(100).to_a")
add_dataset(datasets dataset.hetero.make.std.array        std.array.cpp.erb           "(0..50).step(10).to_a + (100..500).step(100).to_a")
add_dataset(datasets dataset.hetero.make.std.tuple        std.tuple.cpp.erb           "(0..50).step(10).to_a + [100]")

add_chart(benchmark.hetero.make DATASETS ${datasets})
