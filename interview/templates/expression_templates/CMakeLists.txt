cmake_minimum_required(VERSION 3.10)
project(expression_templates)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES expression_templates.cpp no_expr_temp.hpp expr_temp.hpp)
add_executable(expression_templates ${SOURCE_FILES})