cmake_minimum_required(VERSION 3.10)
project(virtual)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES virtual.cpp A.hpp B.hpp C.hpp D.hpp)
add_executable(virtual ${SOURCE_FILES})