cmake_minimum_required(VERSION 3.15)
project(ReadFileAsyncWinAPI)

set(
	SRC_FILES
	ReadFileOverlapped.cpp
)
add_executable(
	ReadFileOverlapped
	${SRC_FILES}
)
set_target_properties(ReadFileOverlapped PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
target_link_libraries(
	ReadFileOverlapped
	ws2_32
)


set(
	SRC_FILES
	ReadFileEx.cpp
)
add_executable(
	ReadFileEx
	${SRC_FILES}
)
set_target_properties(ReadFileEx PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
target_link_libraries(
	ReadFileEx
	ws2_32
)
