# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
#
# This CMake module guesses the most recent version of the C++ standard
# supported by ${CMAKE_CXX_COMPILER}, and sets the CXX_STANDARD variable
# to that version. Note that CXX_STANDARD is the full year of the version
# (e.g. 1998 or 2011 instead of 98 or 11), so that versions can be compared
# with LESS and GREATER.

set(SOURCE_FILE ${CMAKE_BINARY_DIR}/_find_cxx_standard.cpp)
file(WRITE "${SOURCE_FILE}"
    "#if __cplusplus < STANDARD_DATE                                \n"
    "#  error                                                       \n"
    "#endif                                                         \n"
    "int main() { }                                                 \n"
)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Check for C++14")
try_compile(_supports_14 ${CMAKE_BINARY_DIR} ${SOURCE_FILE}
    CMAKE_FLAGS -DCMAKE_CXX_STANDARD=14
    COMPILE_DEFINITIONS -DSTANDARD_DATE=201402L
)
if (_supports_14)
    set(CXX_STANDARD 2014)
    set(CMAKE_CXX_STANDARD 14)
    message(STATUS "Check for C++14 -- works")
    return()
endif()

message(STATUS "Check for C++11")
try_compile(_supports_11 ${CMAKE_BINARY_DIR} ${SOURCE_FILE}
    CMAKE_FLAGS -DCMAKE_CXX_STANDARD=11
    COMPILE_DEFINITIONS -DSTANDARD_DATE=201103L
)
if (_supports_11)
    set(CXX_STANDARD 2011)
    set(CMAKE_CXX_STANDARD 11)
    message(STATUS "Check for C++11 -- works")
    return()
endif()

message(STATUS "Check for C++98")
try_compile(_supports_98 ${CMAKE_BINARY_DIR} ${SOURCE_FILE}
    CMAKE_FLAGS -DCMAKE_CXX_STANDARD=98
    COMPILE_DEFINITIONS -DSTANDARD_DATE=199711L
)
if (_supports_98)
    set(CXX_STANDARD 1998)
    set(CMAKE_CXX_STANDARD 98)
    message(STATUS "Check for C++98 -- works")
return()
endif()

# Emit an error if none of the standards are satisfied.
message(FATAL_ERROR
    "FindCXXStandard.cmake: The C++ compiler '${CMAKE_CXX_COMPILER}' appears "
    "not to support any of the known standard (1998, 2011, 2014)."
)
