set(SOURCE_FILES1 bad.cpp)
set(EXECUTABLE1 aads_tree_traverse_bad)
add_executable(${EXECUTABLE1} ${SOURCE_FILES1})
set_target_properties(${EXECUTABLE1} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

set(SOURCE_FILES2 new.cpp)
set(EXECUTABLE2 aads_tree_traverse)
add_executable(${EXECUTABLE2} ${SOURCE_FILES2})
set_target_properties(${EXECUTABLE2} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

if(MSVC)
  target_compile_options(${EXECUTABLE1} PRIVATE /W4 /WX)
  target_compile_options(${EXECUTABLE2} PRIVATE /W4 /WX)
else()
  target_compile_options(${EXECUTABLE1} PRIVATE -Wall -Wextra -pedantic -Werror)
  target_compile_options(${EXECUTABLE2} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
