cmake_minimum_required(VERSION 3.10)
project(functions_overload)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES functions_overload.cpp auto_overload_resolution.hpp)
add_executable(functions_overload ${SOURCE_FILES})