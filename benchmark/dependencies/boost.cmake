# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

if (METABENCH_FUSION OR METABENCH_MPL)
    find_package(Boost QUIET)
    if (Boost_FOUND)
        message(STATUS "Boost found - version ${Boost_VERSION}")
        include_directories(${Boost_INCLUDE_DIRS})
    else()
        message(WARNING "Boost not found - Fusion and MPL will be unavailable.")
    endif()
endif()

function(Fusion_add_dataset dataset path_to_template range)
    if (Boost_FOUND AND METABENCH_FUSION)
        string(REGEX REPLACE "[^.]+[.][^.]+[.][^.]+[.](.*)" "\\1" name ${dataset})
        metabench_add_dataset(${dataset} ${path_to_template} ${range} NAME ${name} MEDIAN_OF 3)
    endif()
endfunction()

function(MPL_add_dataset dataset path_to_template range)
    if (Boost_FOUND AND METABENCH_MPL)
        string(REGEX REPLACE "[^.]+[.][^.]+[.][^.]+[.](.*)" "\\1" name ${dataset})
        metabench_add_dataset(${dataset} ${path_to_template} ${range} NAME ${name} MEDIAN_OF 3)
    endif()
endfunction()
