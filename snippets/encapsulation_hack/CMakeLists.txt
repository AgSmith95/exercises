cmake_minimum_required(VERSION 3.10)
project(encapsulation_hack)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
set(EXECUTABLE encapsulation_hack)
add_executable(${EXECUTABLE} ${SOURCE_FILES})

if(MSVC)
  target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
else()
  target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
