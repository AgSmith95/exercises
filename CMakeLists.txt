cmake_minimum_required(VERSION 3.10)
project(exercises)

option(
	BUILD_ASM
	"Build asm"
	OFF
)
if(BUILD_ASM)
	add_subdirectory(asm)
endif()

option(
	BUILD_INTERVIEW
	"Build interview"
	OFF
)
if(BUILD_INTERVIEW)
	add_subdirectory(interview)
endif()

option(
	BUILD_MULTITHREADING
	"Build multithreading"
	OFF
)
if(BUILD_MULTITHREADING)
	add_subdirectory(multithreading)
endif()
