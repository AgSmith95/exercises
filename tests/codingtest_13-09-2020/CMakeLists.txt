cmake_minimum_required(VERSION 3.10)
project(project)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp one.cpp two.h two.cpp)
set(EXECUTABLE test-13-09)
add_executable(${EXECUTABLE} ${SOURCE_FILES})

if(MSVC)
  target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
else()
  target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
