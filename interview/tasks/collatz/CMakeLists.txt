cmake_minimum_required(VERSION 3.10)
project(collatz)

set(SOURCE_FILES main.cpp)
set(EXECUTABLE collatz)
add_executable(${EXECUTABLE} ${SOURCE_FILES})

set(SOURCE_FILES2 main_readable.cpp)
set(EXECUTABLE2 collatz_readable)
add_executable(${EXECUTABLE2} ${SOURCE_FILES2})

set(SOURCE_FILES3 main_cache.cpp)
set(EXECUTABLE3 collatz_cached)
add_executable(${EXECUTABLE3} ${SOURCE_FILES3})

if(MSVC)
  target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
  target_compile_options(${EXECUTABLE2} PRIVATE /W4 /WX)
  target_compile_options(${EXECUTABLE3} PRIVATE /W4 /WX)
else()
  target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
  target_compile_options(${EXECUTABLE3} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
