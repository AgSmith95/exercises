set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(EXECUTABLE_NAME_SET linux_shmem_set_bin)
set(SOURCE_FILES set.cpp)
add_executable(${EXECUTABLE_NAME_SET} ${SOURCE_FILES})
target_link_libraries(
    ${EXECUTABLE_NAME_SET}
    Threads::Threads
    rt
)
set_target_properties(${EXECUTABLE} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

set(EXECUTABLE_NAME_GET linux_shmem_get_bin)
set(SOURCE_FILES get.cpp)
add_executable(${EXECUTABLE_NAME_GET} ${SOURCE_FILES})
target_link_libraries(
    ${EXECUTABLE_NAME_GET}
    Threads::Threads
    rt
)
set_target_properties(${EXECUTABLE_NAME_GET} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
