# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set(datasets)
add_dataset(datasets hetero fold_right fusion vector      fusion.vector.cpp.erb    "(0..50).step(10)"                        ENV "{k: 3}")
add_dataset(datasets hetero fold_right hana   basic_tuple hana.basic_tuple.cpp.erb "(0..50).step(10).to_a + [100, 200, 300]" ENV "{k: 3}")
add_dataset(datasets hetero fold_right hana   tuple       hana.tuple.cpp.erb       "(0..50).step(10).to_a + [100, 200, 300]" ENV "{k: 3}")

add_chart(hetero fold_right DATASETS ${datasets})
