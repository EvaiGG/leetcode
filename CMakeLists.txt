cmake_minimum_required(VERSION 3.20)
include_directories(SYSTEM "/foo/bar")
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode   f14_solution.cpp)
#add_executable(leetcode demo/repl.cpp)
