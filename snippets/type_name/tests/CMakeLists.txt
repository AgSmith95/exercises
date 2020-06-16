cmake_minimum_required(VERSION 3.10)
set(TEST_BIN_NAME type_name_test)

add_executable(${TEST_BIN_NAME})
target_sources(
    ${TEST_BIN_NAME}
    PRIVATE
    type_name.cpp
)
target_link_libraries(
    ${TEST_BIN_NAME}
    type_name
)

if(MSVC)
    target_compile_options(${TEST_BIN_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${TEST_BIN_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
