# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set(datasets)
add_dataset(datasets hetero at_key fusion map   fusion.map.cpp.erb "[1] + (10..50).step(10).to_a"                   ENV "{k: 1}")
add_dataset(datasets hetero at_key hana   map   hana.map.cpp.erb   "[1] + (10..50).step(10).to_a + [100, 200, 300]" ENV "{k: 1}")
add_dataset(datasets hetero at_key hana   tuple hana.tuple.cpp.erb "[1] + (10..50).step(10).to_a + [100, 200, 300]" ENV "{k: 1}")

add_chart(hetero at_key DATASETS ${datasets})
