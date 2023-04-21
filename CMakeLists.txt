cmake_minimum_required(VERSION 3.20)
#include_directories(SYSTEM "/foo/bar")
project(leetcode)

set(CMAKE_CXX_STANDARD 17)

add_executable(leetcode   day7_solution.cpp day8_solution.cpp)
#add_executable(leetcode   main.cpp)
