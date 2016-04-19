# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

metabench_add_dataset(example.std_tuple make_tuple/std_tuple.cpp.erb "(0...50).step(5)" NAME std::tuple)
metabench_add_dataset(example.recursive_tuple make_tuple/recursive_tuple.cpp.erb "(0...50).step(5)" NAME "recursive tuple")
metabench_add_chart(example.make_tuple
    TITLE "Creating a heterogeneous container with n elements"
    SUBTITLE "(smaller is better)"
    DATASETS example.std_tuple example.recursive_tuple
)

metabench_add_dataset(example.std_decay decay/std_decay.cpp.erb "(0...500).step(100)" NAME std::decay)

metabench_add_dataset(example.my_decay decay/my_decay.cpp.erb "(0...500).step(100)" NAME "my decay")
add_custom_target(should_trigger_the_bug
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/example.std_decay.json
            ${CMAKE_CURRENT_BINARY_DIR}/example.my_decay.json)


metabench_add_chart(example.decay
    TITLE "Calling a decay metafunction on n different types"
    SUBTITLE "(smaller is better)"
    XLABEL "Number of types"
    YLABEL "Time"
    DATASETS example.my_decay
)

add_custom_target(examples ALL DEPENDS example.decay example.make_tuple)
