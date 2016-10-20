# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set(datasets)
add_dataset(datasets hetero at fusion list        fusion.list.cpp.erb      "(0..50).step(10).to_a"                            ENV "{k: 3, p: 100}")
add_dataset(datasets hetero at fusion vector      fusion.vector.cpp.erb    "(0..50).step(10).to_a + [100]"                    ENV "{k: 3, p: 100}")
add_dataset(datasets hetero at hana   basic_tuple hana.basic_tuple.cpp.erb "(0..50).step(10).to_a + (100..300).step(50).to_a" ENV "{k: 3, p: 100}")
add_dataset(datasets hetero at hana   tuple       hana.tuple.cpp.erb       "(0..50).step(10).to_a + (100..300).step(50).to_a" ENV "{k: 3, p: 100}")
add_dataset(datasets hetero at std    tuple       std.tuple.cpp.erb        "(0..50).step(10).to_a + [100]"                    ENV "{k: 3, p: 100}")

add_chart(hetero at DATASETS ${datasets})
