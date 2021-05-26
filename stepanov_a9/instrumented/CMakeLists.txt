cmake_minimum_required(VERSION 3.10)
project(instrumented)
set(CMAKE_CXX_STANDARD 20)

# library for instrumented
add_library(
    instrumented_lib
    STATIC
    src/instrumented.cpp
)
target_include_directories(
    instrumented_lib

    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>

    PRIVATE
    src
)

# TESTS
add_executable(
    test_instrumented
    test/test_instrumented.cpp
)

target_link_libraries(
    test_instrumented
    instrumented_lib
)

# Add tests to lib
add_test(instrumented_lib test_instrumented)
