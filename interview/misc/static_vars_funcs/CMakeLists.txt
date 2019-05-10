cmake_minimum_required(VERSION 3.10)
project(static_vfs)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp a.h b.cpp b.h c.cpp c.h a.cpp)
add_executable(static_vfs ${SOURCE_FILES})