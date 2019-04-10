cmake_minimum_required(VERSION 3.10)
project(ppp_inheritance)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES expression_templates.cpp no_expr_temp.hpp expr_temp.hpp)
add_executable(pub_pro_pri.exe ${SOURCE_FILES})