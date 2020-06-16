cmake_minimum_required(VERSION 3.10)
project(type_name)
set(CMAKE_CXX_STANDARD 17)

set(LIB_NAME type_name)

FILE(
    GLOB
    HEADER_FILES
    "include/*.h*"
)

add_library(
    ${LIB_NAME}
    INTERFACE
)

target_include_directories(
    ${LIB_NAME}
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if(MSVC)
  target_compile_options(${LIB_NAME} INTERFACE /W4 /WX)
else()
  target_compile_options(${LIB_NAME} INTERFACE -Wall -Wextra -pedantic -Werror)
endif()

enable_testing()
add_subdirectory(tests)
