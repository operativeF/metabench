# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set(datasets)
add_dataset(datasets type fold_right brigand list   brigand.list.cpp.erb "(0..50).step(10).to_a + (100..500).step(50).to_a" ENV "{k: 30}")
add_dataset(datasets type fold_right meta    list   meta.list.cpp.erb    "(0..50).step(10).to_a + (100..500).step(50).to_a" ENV "{k: 30}")
add_dataset(datasets type fold_right metal   list   metal.list.cpp.erb   "(0..50).step(10).to_a + (100..500).step(50).to_a" ENV "{k: 30}")
add_dataset(datasets type fold_right mpl     list   mpl.list.cpp.erb     "(0..50).step(10)"                                 ENV "{k: 30}")
add_dataset(datasets type fold_right mpl     vector mpl.vector.cpp.erb   "(0..50).step(10)"                                 ENV "{k: 30}")

add_chart(type fold_right DATASETS ${datasets})
