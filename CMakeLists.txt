# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.1)
find_package(Ruby 2.1)

file(WRITE main.cpp "int main() { }\n")
add_executable(main main.cpp)
add_custom_target(make_main
    COMMAND ${RUBY_EXECUTABLE} -r time -r fileutils
        -e "100.times do |i|"
        -e "  puts %{#{i+1}th time}"
        -e "  FileUtils.touch('main.cpp', mtime: Time.now+1)"
        -e "  output = `\"${CMAKE_COMMAND}\" --build \"${CMAKE_BINARY_DIR}\" --target main`"
        -e "  raise output if not $?.success?"
        -e "end"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    VERBATIM
)
