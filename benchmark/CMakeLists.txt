# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.1)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/..")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(metabench)


# Check for dependencies
find_package(Boost)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(Meta_CLONE_IF_MISSING ON)
find_package(Meta)
if (Meta_FOUND)
    include_directories(${Meta_INCLUDE_DIR})
endif()

# find_package(Metal)
# if (Metal_FOUND)
#     include_directories(${Metal_INCLUDE_DIR})
# endif()

# find_package(Brigand)
# if (Brigand_FOUND)
#     include_directories(${Brigand_INCLUDE_DIR})
# endif()

function(dependencies_are_satisfied result dataset)
    if(${dataset} MATCHES "brigand\\.")
        set(${result} OFF PARENT_SCOPE)
    elseif(${dataset} MATCHES "meta\\.")
        set(${result} ${Meta_FOUND} PARENT_SCOPE)
    elseif(${dataset} MATCHES "metal\\.")
        set(${result} OFF PARENT_SCOPE)
    elseif (${dataset} MATCHES "mpl\\.")
        set(${result} ${Boost_FOUND} PARENT_SCOPE)
    endif()
endfunction()

add_subdirectory(type/at)
