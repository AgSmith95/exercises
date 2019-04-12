cmake_minimum_required(VERSION 3.10)
project(lrvalues)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES lrvalues.cpp X.hpp A.hpp)
add_executable(lrvalues ${SOURCE_FILES})