# Copyright Louis Dionne 2017
#           Thomas Figueroa 2021
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

function(metabench_add_dataset target path_to_template min max steps)
    set(options)
    set(one_value_args FILENAME ENV COLOR SCALE MEDIAN_OF OUTPUT)
    cmake_parse_arguments(ARGS "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

    if (NOT IS_ABSOLUTE "${path_to_template}")
        set(path_to_template "${CMAKE_CURRENT_SOURCE_DIR}/${path_to_template}")
    endif()
    if (NOT EXISTS ${path_to_template})
        message(FATAL_ERROR "The file specified to metabench_add_dataset (${path_to_template}) does not exist.")
    endif()

    if (NOT ARGS_NAME)
        set(ARGS_NAME ${target})
    endif()

    if (NOT ARGS_ENV)
        set(ARGS_ENV "{}")
    endif()

    if (NOT ARGS_COLOR)
        set(ARGS_COLOR "")
    endif()

    if (NOT ARGS_SCALE)
        set(ARGS_SCALE 1.0)
    endif()

    if (NOT ARGS_MEDIAN_OF)
        set(ARGS_MEDIAN_OF 1)
    endif()

    if (NOT ARGS_OUTPUT)
        set(ARGS_OUTPUT "${target}.json")
    endif()
    if(NOT IS_ABSOLUTE "${ARGS_OUTPUT}")
        set(ARGS_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${ARGS_OUTPUT}")
    endif()
endfunction()

# metabench_add_chart(example.decay
#     TITLE "Calling a decay metafunction on n different types"
#     SUBTITLE "(smaller is better)"
#     XLABEL "Number of types"
#     YLABEL "Time"
#     DATASETS example.std_decay example.my_decay
# )