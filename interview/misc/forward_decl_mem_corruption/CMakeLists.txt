set(EXECUTABLE misc_forward_decl_mem_corr)

set(SOURCE_FILES main.cpp)
add_executable(${EXECUTABLE} ${SOURCE_FILES})

set_target_properties(${EXECUTABLE} PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED ON
	)
target_compile_options(${EXECUTABLE} PRIVATE
	-masm=intel
)

# errors are intentional
# if(MSVC)
# 	target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
# else()
# 	target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
# endif()
