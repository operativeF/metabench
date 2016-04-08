# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

if (METABENCH_FUSION OR METABENCH_MPL)
    find_package(Boost QUIET)
    if (Boost_FOUND)
        message(STATUS "Local Boost installation found - version ${Boost_VERSION}")
    else()
        message(STATUS "No local Boost installation found - Fusion and MPL will be unavailable.")
    endif()
endif()

function(Fusion_add_dataset dataset)
    if (Boost_FOUND AND METABENCH_FUSION)
        metabench_add_dataset(${dataset} ${ARGN} MEDIAN_OF 3)
        target_include_directories(${dataset} PUBLIC ${Boost_INCLUDE_DIRS})
    endif()
endfunction()

function(MPL_add_dataset dataset)
    if (Boost_FOUND AND METABENCH_MPL)
        metabench_add_dataset(${dataset} ${ARGN} MEDIAN_OF 3)
        target_include_directories(${dataset} PUBLIC ${Boost_INCLUDE_DIRS})
    endif()
endfunction()
