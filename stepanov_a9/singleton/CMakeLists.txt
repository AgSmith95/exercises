cmake_minimum_required(VERSION 3.10)
project(singleton)
set(CMAKE_CXX_STANDARD 20)

# library for singleton
add_library(
    singleton_lib
    INTERFACE
)
target_include_directories(
    singleton_lib
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# test for singleton
add_executable(
    test_singleton
    test_singleton.cpp
)
target_link_libraries(
    test_singleton
    singleton_lib
)

# add test
add_test(
    singleton_lib
    test_singleton
)