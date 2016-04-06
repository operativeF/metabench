# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

if (METABENCH_HANA
    AND NOT (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND
             CMAKE_CXX_COMPILER_VERSION VERSION_LESS "6")
    AND NOT (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
)
    find_package(Hana QUIET)
    if (Hana_FOUND)
        message(STATUS "Hana found - version ${Hana_VERSION}")
        include_directories(${Hana_INCLUDE_DIRS})
        add_custom_target(Hana)
    else()
        include(ExternalProject)
        message(STATUS "Hana not found - fetching branch develop")
        ExternalProject_Add(Hana EXCLUDE_FROM_ALL 1
            URL https://github.com/ldionne/hana/archive/develop.zip
            TIMEOUT 120
            PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
            CONFIGURE_COMMAND "" # Disable configure step
            BUILD_COMMAND ""     # Disable build step
            INSTALL_COMMAND ""   # Disable install step
            TEST_COMMAND ""      # Disable test step
            UPDATE_COMMAND ""    # Disable source work-tree update
        )
        ExternalProject_Get_Property(Hana SOURCE_DIR)
        include_directories(${SOURCE_DIR}/include)
    endif()

    function(Hana_add_dataset dataset path_to_template range)
        string(REGEX REPLACE "[^.]+[.][^.]+[.][^.]+[.](.*)" "\\1" name ${dataset})
        metabench_add_dataset(${dataset} ${path_to_template} ${range} NAME ${name})
        add_dependencies(${dataset} Hana)
    endfunction()
else()
    function(Hana_add_dataset)
    endfunction()
endif()
