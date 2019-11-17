cmake_minimum_required(VERSION 3.10)
project(fdecl_mem_corr)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-masm=intel")

set(SOURCE_FILES main.cpp)
add_executable(fdecl_mem_corr ${SOURCE_FILES})