# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

option(METABENCH_BRIGAND    "Benchmark Brigand" ON)
option(METABENCH_FUSION     "Benchmark Fusion"  ON)
option(METABENCH_HANA       "Benchmark Hana"    ON)
option(METABENCH_META       "Benchmark Meta"    ON)
option(METABENCH_METAL      "Benchmark Metal"   ON)
option(METABENCH_MPL        "Benchmark MPL"     ON)

include(ExternalProject)

if (METABENCH_FUSION OR METABENCH_MPL)
    find_package(Boost)
    if (Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
    endif()
endif()

if (METABENCH_BRIGAND)
    find_package(Brigand QUIET)
    if (Brigand_FOUND)
        message(STATUS "Brigand version: ${Brigand_VERSION}")
        #TODO: add directories here
        add_custom_target(Brigand)
    else()
        message(STATUS "Brigand version: origin/master")
        ExternalProject_Add(Brigand
            GIT_REPOSITORY https://github.com/edouarda/brigand
            GIT_TAG origin/master
            TIMEOUT 10
            CMAKE_ARGS -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
            PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
            BUILD_COMMAND ""   # Disable build step
            INSTALL_COMMAND "" # Disable install step
            TEST_COMMAND ""    # Disable test step
        )
        ExternalProject_Get_Property(Brigand SOURCE_DIR)
        include_directories(${SOURCE_DIR})
    endif()
endif()

if (METABENCH_HANA)
    find_package(Hana QUIET)
    if (Hana_FOUND)
        message(STATUS "Hana version: ${Hana_VERSION}")
        #TODO: add directories here
        add_custom_target(Hana)
    else()
        message(STATUS "Hana version: origin/develop")
        ExternalProject_Add(Hana
            GIT_REPOSITORY https://github.com/ldionne/hana
            GIT_TAG origin/develop
            TIMEOUT 10
            CMAKE_ARGS -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
            PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
            BUILD_COMMAND ""   # Disable build step
            INSTALL_COMMAND "" # Disable install step
            TEST_COMMAND ""    # Disable test step
        )
        ExternalProject_Get_Property(Hana SOURCE_DIR)
        include_directories(${SOURCE_DIR}/include)
    endif()
endif()

if (METABENCH_META)
    find_package(Meta QUIET)
    if (Meta_FOUND)
        message(STATUS "Meta version: ${Meta_VERSION}")
        #TODO: add directories here
        add_custom_target(Meta)
    else()
        message(STATUS "Meta version: origin/master")
        ExternalProject_Add(Meta
            GIT_REPOSITORY https://github.com/ericniebler/meta
            GIT_TAG origin/master
            TIMEOUT 10
            CMAKE_ARGS -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
            PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
            BUILD_COMMAND ""   # Disable build step
            INSTALL_COMMAND "" # Disable install step
            TEST_COMMAND ""    # Disable test step
        )
        ExternalProject_Get_Property(Meta SOURCE_DIR)
        include_directories(${SOURCE_DIR}/include)
    endif()
endif()

if (METABENCH_METAL)
    find_package(Metal QUIET)
    if (Metal_FOUND)
        message(STATUS "Metal version: ${Metal_VERSION}")
        include_directories(${METAL_INCLUDE_DIRS})
        add_custom_target(Metal)
    else()
        message(STATUS "Metal version: origin/master")
        ExternalProject_Add(Metal
            GIT_REPOSITORY https://github.com/brunocodutra/metal
            GIT_TAG origin/master
            TIMEOUT 10
            CMAKE_ARGS -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
            PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
            BUILD_COMMAND ""   # Disable build step
            INSTALL_COMMAND "" # Disable install step
            TEST_COMMAND ""    # Disable test step
        )
        ExternalProject_Get_Property(Metal SOURCE_DIR)
        include_directories(${SOURCE_DIR}/include)
    endif()
endif()

function(dependencies_are_satisfied result dataset)
    if(${dataset} MATCHES "brigand\\.")
        set(${result} ${METABENCH_BRIGAND} PARENT_SCOPE)
    elseif(${dataset} MATCHES "fusion\\.")
        set(${result} ${METABENCH_FUSION} PARENT_SCOPE)
    elseif(${dataset} MATCHES "hana\\.")
        set(${result} ${METABENCH_HANA} PARENT_SCOPE)
    elseif(${dataset} MATCHES "meta\\.")
        set(${result} ${METABENCH_META} PARENT_SCOPE)
    elseif(${dataset} MATCHES "metal\\.")
        set(${result} ${METABENCH_METAL} PARENT_SCOPE)
    elseif (${dataset} MATCHES "mpl\\.")
        set(${result} ${METABENCH_MPL} PARENT_SCOPE)
    elseif (${dataset} MATCHES "std\\.")
        set(${result} ON PARENT_SCOPE) # std:: is always available
    else()
        message(FATAL_ERROR
            "The dataset named '${dataset}' does not appear to benchmark any "
            "known metaprogramming library."
        )
    endif()
endfunction()


add_custom_target(benchmarks)

add_subdirectory(hetero/at)
add_subdirectory(hetero/make)
add_subdirectory(hetero/transform)

add_subdirectory(type/at)
add_subdirectory(type/reverse)
add_subdirectory(type/transform)
