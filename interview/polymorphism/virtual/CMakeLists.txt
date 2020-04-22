cmake_minimum_required(VERSION 3.10)
project(virtual)
set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE virtual)

set(
    SOURCE_FILES

    virtual.cpp
    A.hpp
    B.hpp
    C.hpp
    D.hpp
    F.hpp
    G.hpp
    OverrideFinal.hpp
)
add_executable(${EXECUTABLE} ${SOURCE_FILES})
