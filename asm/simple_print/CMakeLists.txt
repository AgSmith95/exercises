cmake_minimum_required(VERSION 3.10)
project(simple_print)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-masm=intel")

set(SOURCE_FILES main.cpp)
add_executable(simple_print ${SOURCE_FILES})