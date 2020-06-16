set(SOURCE_FILES map.cpp)
set(EXECUTABLE basics)
add_executable(${EXECUTABLE} ${SOURCE_FILES})

if(MSVC)
    target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
else()
    target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
