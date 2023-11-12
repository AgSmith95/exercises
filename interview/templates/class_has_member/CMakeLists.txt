# cmake_minimum_required(VERSION 3.10)
# project(project)

# exec1
set(SOURCE_FILES class_has_member.cpp)
set(EXECUTABLE tmpl_class_has_member)
add_executable(${EXECUTABLE} ${SOURCE_FILES})

set_target_properties(${EXECUTABLE} PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)

if(MSVC)
	target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
else()
	target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

#exec 2
set(SOURCE_FILES2 class_has_member_type.cpp)
set(EXECUTABLE2 tmpl_class_has_member_type)
add_executable(${EXECUTABLE2} ${SOURCE_FILES2})

set_target_properties(${EXECUTABLE2} PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)

if(MSVC)
	target_compile_options(${EXECUTABLE2} PRIVATE /W4 /WX)
else()
	target_compile_options(${EXECUTABLE2} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

#exec 3
set(SOURCE_FILES3 class_has_member_concept.cpp)
set(EXECUTABLE3 tmpl_class_has_member_concept)
add_executable(${EXECUTABLE3} ${SOURCE_FILES3})

set_target_properties(${EXECUTABLE3} PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)

if(MSVC)
	target_compile_options(${EXECUTABLE3} PRIVATE /W4 /WX)
else()
	target_compile_options(${EXECUTABLE3} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
