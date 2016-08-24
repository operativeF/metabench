# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

option(METABENCH_BRIGAND    "Benchmark Brigand" ON)
option(METABENCH_FUSION     "Benchmark Fusion"  ON)
option(METABENCH_HANA       "Benchmark Hana"    ON)
option(METABENCH_META       "Benchmark Meta"    ON)
option(METABENCH_METAL      "Benchmark Metal"   ON)
option(METABENCH_MPL        "Benchmark MPL"     ON)


include(benchmark/dependencies/brigand)
include(benchmark/dependencies/fusion)
include(benchmark/dependencies/hana)
include(benchmark/dependencies/meta)
include(benchmark/dependencies/metal)
include(benchmark/dependencies/mpl)
include(benchmark/dependencies/std)


macro(add_dataset datasets dataset path_to_template range)
    string(REGEX REPLACE "[^.]+[.][^.]+[.][^.]+[.](.*)" "\\1" name ${dataset})
    set(args ${dataset} ${path_to_template} ${range} NAME ${name} OUTPUT ${name}.json ${ARGN} MEDIAN_OF 3)

    if(${dataset} MATCHES "brigand\\.")
        Brigand_add_dataset(${args})
    elseif(${dataset} MATCHES "fusion\\.")
        Fusion_add_dataset(${args})
    elseif(${dataset} MATCHES "hana\\.")
        Hana_add_dataset(${args})
    elseif(${dataset} MATCHES "meta\\.")
        Meta_add_dataset(${args})
    elseif(${dataset} MATCHES "metal\\.")
        Metal_add_dataset(${args})
    elseif (${dataset} MATCHES "mpl\\.")
        MPL_add_dataset(${args})
    elseif (${dataset} MATCHES "std\\.")
        Std_add_dataset(${args})
    else()
        message(FATAL_ERROR
            "The dataset named '${dataset}' does not appear to benchmark any "
            "known metaprogramming library."
        )
    endif()

    if (TARGET ${dataset})
        list(APPEND ${datasets} ${dataset})
    endif()
endmacro()

add_custom_target(benchmarks)
macro(add_chart target)
    cmake_parse_arguments(ARGS "" "" "DATASETS" ${ARGN})

    # If we have no datasets, perhaps they were all disabled in the current
    # configuration. In this case, we omit the benchmark instead of failing.
    list(LENGTH ARGS_DATASETS _n_datasets)
    if (_n_datasets GREATER 0)
        metabench_add_chart(${target} ${ARGN} OUTPUT index.html)
        add_dependencies(benchmarks ${target})
    endif()
endmacro()


set(CMAKE_CXX_STANDARD 14)
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag(-ftemplate-depth=5000 HAS_FTEMPLATE_DEPTH)
if(HAS_FTEMPLATE_DEPTH)
    add_compile_options(-ftemplate-depth=5000)
endif()

file(GLOB benchmark_dirs
    LIST_DIRECTORIES true
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "hetero/*" "type/*"
)

foreach(benchmark_dir ${benchmark_dirs})
    add_subdirectory(${benchmark_dir})
endforeach()
