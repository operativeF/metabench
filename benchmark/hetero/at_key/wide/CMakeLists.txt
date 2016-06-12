# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set(datasets)
add_dataset(datasets dataset.hetero.at_key-wide.fusion.map fusion.map.cpp.erb "(0..100).step(10).to_a" ENV "{range: (0..150).to_a}")
add_dataset(datasets dataset.hetero.at_key-wide.hana.map   hana.map.cpp.erb   "(0..150).step(10).to_a" ENV "{range: (0..150).to_a}")
add_dataset(datasets dataset.hetero.at_key-wide.hana.tuple hana.tuple.cpp.erb "(0..150).step(10).to_a" ENV "{range: (0..150).to_a}")

add_chart(benchmark.hetero.at_key-wide DATASETS ${datasets})
