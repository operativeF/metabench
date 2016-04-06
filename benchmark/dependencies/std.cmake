# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

function(Std_add_dataset dataset path_to_template range)
    if (NOT (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" AND
             CMAKE_CXX_COMPILER_VERSION VERSION_LESS "19"))
        string(REGEX REPLACE "[^.]+[.][^.]+[.][^.]+[.](.*)" "\\1" name ${dataset})
        metabench_add_dataset(${dataset} ${path_to_template} ${range} NAME ${name})
    endif()
endfunction()
