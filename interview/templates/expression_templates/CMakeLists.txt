set(SOURCE_FILES
	expression_templates.cpp
	no_expr_temp.hpp
	expr_temp.hpp
)
set(EXECUTABLE tmpl_expression_templates)
add_executable(${EXECUTABLE} ${SOURCE_FILES})

set_target_properties(${EXECUTABLE} PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED ON
)

if(MSVC)
	target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
else()
	target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
