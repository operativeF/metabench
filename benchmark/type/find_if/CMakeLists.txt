# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set(datasets)
add_dataset(datasets dataset.type.find_if.brigand.list              brigand.list.cpp.erb                "(0...500).step(10)")
add_dataset(datasets dataset.type.find_if.hana.std_integer_sequence hana.std_integer_sequence.cpp.erb   "(0...50).step(5).to_a + (50..400).step(25).to_a")
add_dataset(datasets dataset.type.find_if.meta.list                 meta.list.cpp.erb                   "(0...500).step(10)")
add_dataset(datasets dataset.type.find_if.metal.list                metal.list.cpp.erb                  "(0...500).step(10)")
add_dataset(datasets dataset.type.find_if.mpl.list                  mpl.list.cpp.erb                    "(0...50).step(5)")
add_dataset(datasets dataset.type.find_if.mpl.vector                mpl.vector.cpp.erb                  "(0...50).step(5)")

add_chart(benchmark.type.find_if DATASETS ${datasets})
