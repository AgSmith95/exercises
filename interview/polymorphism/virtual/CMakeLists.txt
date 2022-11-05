set(EXECUTABLE polymorphism_virtual)

set(
    SOURCE_FILES

    virtual.cpp
    A.hpp
    B.hpp
    C.hpp
    D.hpp
    F.hpp
    G.hpp
    OverrideFinal.hpp
)
add_executable(${EXECUTABLE} ${SOURCE_FILES})

set_target_properties(${EXECUTABLE} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

# error handling intentionally turned off
# if(MSVC)
# 	target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
# else()
# 	target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
# endif()
