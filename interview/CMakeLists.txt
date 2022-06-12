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

# add_subdirectory(exceptions)
# add_subdirectory(functions)
# add_subdirectory(inheritance)
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
