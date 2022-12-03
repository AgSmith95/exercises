if(BUILD_MULTITHREADING_COND_VAR)
	add_subdirectory(condition_variable)
endif()

if(BUILD_MULTITHREADING_TASK_SCHED)
	add_subdirectory(task_scheduler)
endif()

if(BUILD_MULTITHREADING_TASK_SYSTEM)
	add_subdirectory(task_system)
endif()
