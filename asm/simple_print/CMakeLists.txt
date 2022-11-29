set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
set(EXECUTABLE asm_simple_print)
add_executable(${EXECUTABLE} ${SOURCE_FILES})

set_target_properties(${EXECUTABLE} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

target_compile_options(${EXECUTABLE} PUBLIC
	-masm=intel
)

# Errors disabled intentionally
# if(MSVC)
#   target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
# else()
#   target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
# endif()
