set(SOURCE_FILES pub_pro_pri.cpp)

set(EXECUTABLE inheritance_pub_pro_pri)
add_executable(${EXECUTABLE} ${SOURCE_FILES})

set_target_properties(${EXECUTABLE} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

# build errors are intentional
# if(MSVC)
# 	target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
# else()
# 	target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
# endif()
