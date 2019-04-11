cmake_minimum_required(VERSION 3.10)
project(perfect_forwarding)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES perfect_forwarding.cpp)
add_executable(perfect_forwarding ${SOURCE_FILES})