cmake_minimum_required(VERSION 3.10)
project(lists_merge)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp SinglyLinkedList.hpp)
add_executable(lists_merge ${SOURCE_FILES})