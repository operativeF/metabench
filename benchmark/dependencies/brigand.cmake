# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

if (METABENCH_BRIGAND)
    find_package(Brigand QUIET)
    if (Brigand_FOUND)
        message(STATUS "Brigand found - version ${Brigand_VERSION}")
        #TODO: add directories here
        add_custom_target(Brigand)
    else()
        include(ExternalProject)
        message(STATUS "Brigand not found - fetching branch master")
        ExternalProject_Add(Brigand EXCLUDE_FROM_ALL 1
            URL https://github.com/edouarda/brigand/archive/master.zip
            TIMEOUT 120
            PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
            CONFIGURE_COMMAND "" # Disable configure step
            BUILD_COMMAND ""     # Disable build step
            INSTALL_COMMAND ""   # Disable install step
            TEST_COMMAND ""      # Disable test step
            UPDATE_COMMAND ""    # Disable source work-tree update
        )
        ExternalProject_Get_Property(Brigand SOURCE_DIR)
        include_directories(${SOURCE_DIR})
    endif()
endif()

function(Brigand_add_dataset dataset path_to_template range)
    if (METABENCH_BRIGAND)
        string(REGEX REPLACE "[^.]+[.][^.]+[.][^.]+[.](.*)" "\\1" name ${dataset})
        metabench_add_dataset(${dataset} ${path_to_template} ${range} NAME ${name})
        add_dependencies(${dataset} Brigand)
    endif()
endfunction()
