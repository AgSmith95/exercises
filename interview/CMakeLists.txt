option(
	BUILD_INTERVIEW_CONTAINERS
	"Build interview/containers"
	OFF
)
if(BUILD_INTERVIEW_CONTAINERS)
	add_subdirectory(containers)
endif()

option(
	BUILD_INTERVIEW_CORE
	"Build interview/core"
	OFF
)
if(BUILD_INTERVIEW_CORE)
	add_subdirectory(core)
endif()

option(
	BUILD_INTERVIEW_DYNAM_PROG
	"Build interview/dynam_prog"
	OFF
)
if(BUILD_INTERVIEW_DYNAM_PROG)
	add_subdirectory(dynam_prog)
endif()

option(
	BUILD_INTERVIEW_EXCEPTIONS
	"Build interview/exceptions"
	OFF
)
if(BUILD_INTERVIEW_EXCEPTIONS)
	add_subdirectory(exceptions)
endif()

option(
	BUILD_INTERVIEW_FUNCTIONS
	"Build interview/functions"
	OFF
)
if(BUILD_INTERVIEW_FUNCTIONS)
	add_subdirectory(functions)
endif()

option(
	BUILD_INTERVIEW_INHERITANCE
	"Build interview/inheritance"
	OFF
)
if(BUILD_INTERVIEW_INHERITANCE)
	add_subdirectory(inheritance)
endif()

# add_subdirectory(iterators)
# add_subdirectory(lambdas)
# add_subdirectory(linux)
# add_subdirectory(memory)
# add_subdirectory(misc)
# add_subdirectory(pointers)
# add_subdirectory(polymorphism)
# add_subdirectory(tasks)
# add_subdirectory(templates)
# add_subdirectory(values)
