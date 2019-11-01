cmake_minimum_required(VERSION 3.10)
project(function_pointers)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES func_pointer.cpp)
add_executable(function_pointers ${SOURCE_FILES})