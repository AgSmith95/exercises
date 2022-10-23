# cmake_minimum_required(VERSION 3.10)
# project(project)

# THREADS
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(EXECUTABLE_NAME executable_w_threads)
set(SOURCE_FILES main.cpp)

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

set_target_properties(${EXECUTABLE} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

# THREADS
target_link_libraries(${EXECUTABLE_NAME} Threads::Threads)

if(MSVC)
  target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
else()
  target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
