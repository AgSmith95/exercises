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
	BUILD_AADS
	"Build aads"
	OFF
)
if(BUILD_AADS)
	add_subdirectory(aads)
endif()

# INTERVIEW | START
	option(
		BUILD_INTERVIEW_CONTAINERS
		"Build interview/containers"
		OFF
	)
	option(
		BUILD_INTERVIEW_DYNAM_PROG
		"Build interview/dynam_prog"
		OFF
	)
	option(
		BUILD_INTERVIEW_EXCEPTIONS
		"Build interview/exceptions"
		OFF
	)
	option(
		BUILD_INTERVIEW_CORE
		"Build interview/core"
		OFF
	)
	option(
		BUILD_INTERVIEW_FUNCTIONS
		"Build interview/functions"
		OFF
	)
	option(
		BUILD_INTERVIEW_INHERITANCE
		"Build interview/inheritance"
		OFF
	)
	option(
		BUILD_INTERVIEW_ITERATORS
		"Build interview/iterators"
		OFF
	)
	option(
		BUILD_INTERVIEW_LAMBDAS
		"Build interview/lambdas"
		OFF
	)
	option(
		BUILD_INTERVIEW_LINUX
		"Build interview/linux"
		OFF
	)
	option(
		BUILD_INTERVIEW_MEMORY
		"Build interview/memory"
		OFF
	)
	option(
		BUILD_INTERVIEW_MISC
		"Build interview/misc"
		OFF
	)
	option(
		BUILD_INTERVIEW_POINTERS
		"Build interview/pointers"
		OFF
	)
	option(
		BUILD_INTERVIEW_POLYMORPHISM
		"Build interview/polymorphism"
		OFF
	)
	option(
		BUILD_INTERVIEW_TASKS
		"Build interview/tasks"
		OFF
	)
	option(
		BUILD_INTERVIEW_TEMPLATES
		"Build interview/templates"
		OFF
	)

if(
	BUILD_INTERVIEW_CONTAINERS OR
	BUILD_INTERVIEW_DYNAM_PROG OR
	BUILD_INTERVIEW_EXCEPTIONS OR
	BUILD_INTERVIEW_CORE OR
	BUILD_INTERVIEW_FUNCTIONS OR
	BUILD_INTERVIEW_INHERITANCE OR
	BUILD_INTERVIEW_ITERATORS OR
	BUILD_INTERVIEW_LAMBDAS OR
	BUILD_INTERVIEW_MEMORY OR
	BUILD_INTERVIEW_MISC OR
	BUILD_INTERVIEW_POINTERS OR
	BUILD_INTERVIEW_POLYMORPHISM OR
	BUILD_INTERVIEW_TASKS OR
	BUILD_INTERVIEW_TEMPLATES
)
	add_subdirectory(interview)
endif()
# INTERVIEW | END

# MULTITHREADING | START
	option(
		BUILD_MULTITHREADING_COND_VAR
		"Build multithreading condition variable"
		OFF
	)
	option(
		BUILD_MULTITHREADING_TASK_SCHED
		"Build multithreading task scheduler"
		OFF
	)
	option(
		BUILD_MULTITHREADING_TASK_SYSTEM
		"Build multithreading task system"
		OFF
	)

if(
	BUILD_MULTITHREADING_COND_VAR OR
	BUILD_MULTITHREADING_TASK_SCHED OR
	BUILD_MULTITHREADING_TASK_SYSTEM
)
	add_subdirectory(multithreading)
endif()
# MULTITHREADING | END
