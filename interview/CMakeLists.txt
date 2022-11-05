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

option(
	BUILD_INTERVIEW_ITERATORS
	"Build interview/iterators"
	OFF
)
if(BUILD_INTERVIEW_ITERATORS)
	add_subdirectory(iterators)
endif()

option(
	BUILD_INTERVIEW_LAMBDAS
	"Build interview/lambdas"
	OFF
)
if(BUILD_INTERVIEW_LAMBDAS)
	add_subdirectory(lambdas)
endif()

option(
	BUILD_INTERVIEW_LINUX
	"Build interview/linux"
	OFF
)
if(BUILD_INTERVIEW_LINUX)
	add_subdirectory(linux)
endif()

option(
	BUILD_INTERVIEW_MEMORY
	"Build interview/memory"
	OFF
)
if(BUILD_INTERVIEW_MEMORY)
	add_subdirectory(memory)
endif()

option(
	BUILD_INTERVIEW_MISC
	"Build interview/misc"
	OFF
)
if(BUILD_INTERVIEW_MISC)
	add_subdirectory(misc)
endif()

option(
	BUILD_INTERVIEW_POINTERS
	"Build interview/pointers"
	OFF
)
if(BUILD_INTERVIEW_POINTERS)
	add_subdirectory(pointers)
endif()

option(
	BUILD_INTERVIEW_POLYMORPHISM
	"Build interview/polymorphism"
	OFF
)
if(BUILD_INTERVIEW_POLYMORPHISM)
	add_subdirectory(polymorphism)
endif()

# add_subdirectory(polymorphism)
# add_subdirectory(tasks)
# add_subdirectory(templates)
# add_subdirectory(values)
