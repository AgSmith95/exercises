cmake_minimum_required(VERSION 3.10)
project(tree_traverse)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES1 bad.cpp)
set(EXECUTABLE1 bad_tree_traverse)
add_executable(${EXECUTABLE1} ${SOURCE_FILES1})

set(SOURCE_FILES2 new.cpp)
set(EXECUTABLE2 tree_traverse)
add_executable(${EXECUTABLE2} ${SOURCE_FILES2})

if(MSVC)
  target_compile_options(${EXECUTABLE1} PRIVATE /W4 /WX)
  target_compile_options(${EXECUTABLE2} PRIVATE /W4 /WX)
else()
  target_compile_options(${EXECUTABLE1} PRIVATE -Wall -Wextra -pedantic -Werror)
  target_compile_options(${EXECUTABLE2} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
