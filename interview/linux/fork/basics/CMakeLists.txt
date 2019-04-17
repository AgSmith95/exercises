cmake_minimum_required(VERSION 3.10)
project(fork_basics)
set(CMAKE_CXX_STANDARD 11)

add_executable(fork_basics fork_process_list.cpp)
add_executable(fork_tree fork_tree.cpp)