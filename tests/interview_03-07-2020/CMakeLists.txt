cmake_minimum_required(VERSION 3.10)
project(project)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
set(EXECUTABLE1 executable1)
add_executable(${EXECUTABLE1} ${SOURCE_FILES})

if(MSVC)
  target_compile_options(${EXECUTABLE1} PRIVATE /W4 /WX)
else()
  target_compile_options(${EXECUTABLE1} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
