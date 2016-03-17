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

find_package(Hana)
if (Hana_FOUND)
    include_directories(${Hana_INCLUDE_DIRS})
endif()

find_package(Metal)
if (Metal_FOUND)
    include_directories(${METAL_INCLUDE_DIRS})
endif()

# find_package(Brigand)
# if (Brigand_FOUND)
#     include_directories(${Brigand_INCLUDE_DIR})
# endif()

function(dependencies_are_satisfied result dataset)
    if(${dataset} MATCHES "brigand\\.")
        set(${result} OFF PARENT_SCOPE)
    elseif(${dataset} MATCHES "fusion\\.")
        set(${result} ${Boost_FOUND} PARENT_SCOPE)
    elseif(${dataset} MATCHES "hana\\.")
        set(${result} ${Hana_FOUND} PARENT_SCOPE)
    elseif(${dataset} MATCHES "meta\\.")
        set(${result} ${Meta_FOUND} PARENT_SCOPE)
    elseif(${dataset} MATCHES "metal\\.")
        set(${result} ${Metal_FOUND} PARENT_SCOPE)
    elseif (${dataset} MATCHES "mpl\\.")
        set(${result} ${Boost_FOUND} PARENT_SCOPE)
    elseif (${dataset} MATCHES "std\\.")
        set(${result} ON PARENT_SCOPE) # std:: is always available
    else()
        message(FATAL_ERROR
            "The dataset named '${dataset}' does not appear to benchmark any "
            "known metaprogramming library.")
    endif()
endfunction()

add_subdirectory(hetero/at)
add_subdirectory(type/at)
