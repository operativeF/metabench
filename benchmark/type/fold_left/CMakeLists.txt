# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set(datasets)
add_dataset(datasets dataset.type.fold_left.mpl.list   mpl.list.cpp.erb   "(1..50).step(1)")
add_dataset(datasets dataset.type.fold_left.mpl.vector mpl.vector.cpp.erb "(1..50).step(1)")

add_chart(benchmark.type.fold_left DATASETS ${datasets})
