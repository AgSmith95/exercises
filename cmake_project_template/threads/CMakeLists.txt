cmake_minimum_required(VERSION 3.10)
project(project_name)
set(CMAKE_CXX_STANDARD 17)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(SOURCE_FILES main.cpp)
add_executable(project_executable ${SOURCE_FILES})
target_link_libraries(project_executable Threads::Threads)
