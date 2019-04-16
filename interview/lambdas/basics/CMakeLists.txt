cmake_minimum_required(VERSION 3.10)
project(lambdas_basics)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES lambdas_basics.cpp Capture.hpp)
add_executable(lambdas_basics ${SOURCE_FILES})