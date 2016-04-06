# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

if (METABENCH_METAL AND NOT (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" AND
                             CMAKE_CXX_COMPILER_VERSION VERSION_LESS "19"))
    find_package(Metal QUIET)
    if (Metal_FOUND)
        message(STATUS "Metal found - version ${Metal_VERSION}")
        include_directories(${METAL_INCLUDE_DIRS})
        add_custom_target(Metal)
    else()
        include(ExternalProject)
        message(STATUS "Metal not found - fetching branch master")
        ExternalProject_Add(Metal EXCLUDE_FROM_ALL 1
            URL https://github.com/brunocodutra/metal/archive/master.zip
            TIMEOUT 120
            PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
            CONFIGURE_COMMAND "" # Disable configure step
            BUILD_COMMAND ""     # Disable build step
            INSTALL_COMMAND ""   # Disable install step
            TEST_COMMAND ""      # Disable test step
            UPDATE_COMMAND ""    # Disable source work-tree update
        )
        ExternalProject_Get_Property(Metal SOURCE_DIR)
        include_directories(${SOURCE_DIR}/include)
    endif()

    function(Metal_add_dataset dataset path_to_template range)
        string(REGEX REPLACE "[^.]+[.][^.]+[.][^.]+[.](.*)" "\\1" name ${dataset})
        metabench_add_dataset(${dataset} ${path_to_template} ${range} NAME ${name})
        add_dependencies(${dataset} Metal)
    endfunction()
else()
    function(Metal_add_dataset)
    endfunction()
endif()
