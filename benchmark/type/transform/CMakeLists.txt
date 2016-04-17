# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set(datasets)
add_dataset(datasets dataset.type.transform.brigand.list    brigand.list.cpp.erb    "(0..500).step(10)")
add_dataset(datasets dataset.type.transform.meta.list       meta.list.cpp.erb       "(0..500).step(10)")
add_dataset(datasets dataset.type.transform.metal.list      metal.list.cpp.erb      "(0..500).step(10)")
add_dataset(datasets dataset.type.transform.mpl.list        mpl.list.cpp.erb        "(0..50).step(1)")
add_dataset(datasets dataset.type.transform.mpl.vector      mpl.vector.cpp.erb      "(0..50).step(1)")

add_chart(benchmark.type.transform DATASETS ${datasets})
