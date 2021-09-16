cmake_minimum_required(VERSION 3.10)
project(longest_increasing_subsequence)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp longest_increasing_subsequence.hpp)
set(EXECUTABLE longest_increasing_subsequence)
add_executable(${EXECUTABLE} ${SOURCE_FILES})

if(MSVC)
  target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
else()
  target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
