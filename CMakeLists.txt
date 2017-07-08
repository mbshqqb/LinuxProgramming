cmake_minimum_required(VERSION 3.6)
project(MyCourseCLion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES curses.cpp)
add_executable(MyCourseCLion ${SOURCE_FILES})