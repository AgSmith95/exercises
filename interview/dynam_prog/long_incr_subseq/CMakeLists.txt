cmake_minimum_required(VERSION 3.10)
project(longest_increasing_subsequence)
set(CMAKE_CXX_STANDARD 17)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_definitions(-DDEBUG="1")
endif()

set(SOURCE_FILES main.cpp longest_increasing_subsequence.hpp test.hpp)
set(EXECUTABLE longest_increasing_subsequence)
add_executable(${EXECUTABLE} ${SOURCE_FILES})

if(MSVC)
  target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
else()
  target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
