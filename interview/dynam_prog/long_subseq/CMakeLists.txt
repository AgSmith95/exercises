set(SOURCE_FILES main.cpp longest_subsequence.hpp)
set(EXECUTABLE dynam_prog_longest_subsequence)
add_executable(${EXECUTABLE} ${SOURCE_FILES})

set_target_properties(${EXECUTABLE} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

if(MSVC)
	target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
else()
	target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
