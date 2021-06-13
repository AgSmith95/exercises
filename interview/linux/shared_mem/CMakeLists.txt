cmake_minimum_required(VERSION 3.10)
project(shared_mem)
set(CMAKE_CXX_STANDARD 17)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(EXECUTABLE_NAME_SET set_bin)
set(SOURCE_FILES set.cpp)
add_executable(${EXECUTABLE_NAME_SET} ${SOURCE_FILES})
target_link_libraries(
    ${EXECUTABLE_NAME_SET}
    Threads::Threads
    rt
)

set(EXECUTABLE_NAME_GET get_bin)
set(SOURCE_FILES get.cpp)
add_executable(${EXECUTABLE_NAME_GET} ${SOURCE_FILES})
target_link_libraries(
    ${EXECUTABLE_NAME_GET}
    Threads::Threads
    rt
)
