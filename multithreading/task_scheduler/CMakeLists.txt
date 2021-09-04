cmake_minimum_required(VERSION 3.10)
project(timed_tasks)
set(CMAKE_CXX_STANDARD 17)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(EXECUTABLE_NAME timed_tasks)
set(SOURCE_FILES main.cpp scheduler.hpp task.hpp)
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} Threads::Threads)
