option(
	BUILD_MULTITHREADING_COND_VAR
	"Build multithreading condition variable"
	OFF
)
if(BUILD_MULTITHREADING_COND_VAR)
	add_subdirectory(condition_variable)
endif()

option(
	BUILD_MULTITHREADING_TASK_SCHED
	"Build multithreading task scheduler"
	OFF
)
if(BUILD_MULTITHREADING_TASK_SCHED)
	add_subdirectory(task_scheduler)
endif()

option(
	BUILD_MULTITHREADING_TASK_SYSTEM
	"Build multithreading task system"
	OFF
)
if(BUILD_MULTITHREADING_TASK_SYSTEM)
	add_subdirectory(task_system)
endif()
