# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

if (METABENCH_META AND NOT (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC"))
    find_package(Meta QUIET)
    if (Meta_FOUND)
        message(STATUS "Meta found - version ${Meta_VERSION}")
        #TODO: add directories here
        add_custom_target(Meta)
    else()
        include(ExternalProject)
        message(STATUS "Meta not found - fetching branch master")
        ExternalProject_Add(Meta EXCLUDE_FROM_ALL 1
            URL https://github.com/ericniebler/meta/archive/master.zip
            TIMEOUT 120
            PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
            CONFIGURE_COMMAND "" # Disable configure step
            BUILD_COMMAND ""     # Disable build step
            INSTALL_COMMAND ""   # Disable install step
            TEST_COMMAND ""      # Disable test step
            UPDATE_COMMAND ""    # Disable source work-tree update
        )
        ExternalProject_Get_Property(Meta SOURCE_DIR)
        include_directories(${SOURCE_DIR}/include)
    endif()

    function(Meta_add_dataset dataset path_to_template range)
        string(REGEX REPLACE "[^.]+[.][^.]+[.][^.]+[.](.*)" "\\1" name ${dataset})
        metabench_add_dataset(${dataset} ${path_to_template} ${range} NAME ${name})
        add_dependencies(${dataset} Meta)
    endfunction()
else()
    function(Meta_add_dataset)
    endfunction()
endif()
