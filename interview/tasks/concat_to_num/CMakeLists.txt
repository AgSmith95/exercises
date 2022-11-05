set(SOURCE_FILES main.cpp)
set(SOURCE_FILES2 another.cpp)
set(EXECUTABLE task_add_up_to_num)
set(EXECUTABLE2 task_LEGO)
add_executable(${EXECUTABLE} ${SOURCE_FILES})
add_executable(${EXECUTABLE2} ${SOURCE_FILES2})

set_target_properties(${EXECUTABLE} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
set_target_properties(${EXECUTABLE2} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

#if(MSVC)
#  target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
#else()
#  target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
#endif()
