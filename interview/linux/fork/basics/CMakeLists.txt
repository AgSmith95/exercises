# FORK BASICS
set(EXECUTABLE1 linux_basics_fork)
add_executable(${EXECUTABLE1} fork_process_list.cpp)
set_target_properties(${EXECUTABLE1} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
if(MSVC)
	target_compile_options(${EXECUTABLE1} PRIVATE /W4 /WX)
else()
	target_compile_options(${EXECUTABLE1} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

# FORK TREE
set(EXECUTABLE2 linux_basics_fork_tree)
add_executable(${EXECUTABLE2} fork_tree.cpp)
set_target_properties(${EXECUTABLE2} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
if(MSVC)
	target_compile_options(${EXECUTABLE2} PRIVATE /W4 /WX)
else()
	target_compile_options(${EXECUTABLE2} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
