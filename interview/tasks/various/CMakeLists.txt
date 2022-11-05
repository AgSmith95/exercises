add_executable(task_maximize_by_2metrics maximize_by_2metrics.cpp)
set_target_properties(task_maximize_by_2metrics PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)

add_executable(task_line_intersection lines_intersection.cpp)
set_target_properties(task_line_intersection PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)

add_executable(task_equal_sum_halves equal_sum_halves.cpp)
set_target_properties(task_equal_sum_halves PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)

add_executable(task_cache cache.cpp)
set_target_properties(task_cache PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)

add_executable(task_permute_to_42 permute_to_42.cpp)
set_target_properties(task_permute_to_42 PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)

add_executable(task_sum_of_integral_parts sum_of_integral_parts.cpp)
set_target_properties(task_sum_of_integral_parts PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)
