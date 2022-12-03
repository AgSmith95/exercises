if(BUILD_INTERVIEW_CONTAINERS)
	add_subdirectory(containers)
endif()

if(BUILD_INTERVIEW_CORE)
	add_subdirectory(core)
endif()

if(BUILD_INTERVIEW_DYNAM_PROG)
	add_subdirectory(dynam_prog)
endif()

if(BUILD_INTERVIEW_EXCEPTIONS)
	add_subdirectory(exceptions)
endif()

if(BUILD_INTERVIEW_FUNCTIONS)
	add_subdirectory(functions)
endif()

if(BUILD_INTERVIEW_INHERITANCE)
	add_subdirectory(inheritance)
endif()

if(BUILD_INTERVIEW_ITERATORS)
	add_subdirectory(iterators)
endif()

if(BUILD_INTERVIEW_LAMBDAS)
	add_subdirectory(lambdas)
endif()

if(BUILD_INTERVIEW_LINUX)
	add_subdirectory(linux)
endif()

if(BUILD_INTERVIEW_MEMORY)
	add_subdirectory(memory)
endif()

if(BUILD_INTERVIEW_MISC)
	add_subdirectory(misc)
endif()

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

option(
	BUILD_INTERVIEW_TASKS
	"Build interview/tasks"
	OFF
)
if(BUILD_INTERVIEW_TASKS)
	add_subdirectory(tasks)
endif()

# add_subdirectory(templates)
# add_subdirectory(values)
