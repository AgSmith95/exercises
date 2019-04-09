cmake_minimum_required(VERSION 3.10)
project(ppp_inheritance)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES templates_basics.cpp)
add_executable(pub_pro_pri.exe ${SOURCE_FILES})