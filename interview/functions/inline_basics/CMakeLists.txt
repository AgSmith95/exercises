cmake_minimum_required(VERSION 3.10)
project(project_name)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp lib.cpp)
add_executable(inline ${SOURCE_FILES})