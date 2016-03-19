# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

include(ExternalProject)

# Add several metaprogramming libraries that we want to benchmark
find_package(Boost)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

find_package(Brigand QUIET)
if (Brigand_FOUND)
    message(STATUS "Brigand version: ${Brigand_VERSION}")
    #add directories here
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

find_package(Hana QUIET)
if (Hana_FOUND)
    message(STATUS "Hana version: ${Hana_VERSION}")
    #add directories here
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

find_package(Meta QUIET)
if (Meta_FOUND)
    message(STATUS "Meta version: ${Meta_VERSION}")
    #add directories here
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

function(dependencies_are_satisfied result dataset)
    if(${dataset} MATCHES "brigand\\.")
        set(${result} ON PARENT_SCOPE)
    elseif(${dataset} MATCHES "fusion\\.")
        set(${result} ${Boost_FOUND} PARENT_SCOPE)
    elseif(${dataset} MATCHES "hana\\.")
        set(${result} ON PARENT_SCOPE)
    elseif(${dataset} MATCHES "meta\\.")
        set(${result} ON PARENT_SCOPE)
    elseif(${dataset} MATCHES "metal\\.")
        set(${result} ON PARENT_SCOPE)
    elseif (${dataset} MATCHES "mpl\\.")
        set(${result} ON PARENT_SCOPE)
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
