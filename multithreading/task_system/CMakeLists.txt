set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

set(EXECUTABLE mt_task_system)
set(SOURCE_FILES main.cpp)
add_executable(${EXECUTABLE} ${SOURCE_FILES})

set_target_properties(${EXECUTABLE} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

target_link_libraries(${EXECUTABLE} Threads::Threads)

if(MSVC)
  target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
else()
  target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

