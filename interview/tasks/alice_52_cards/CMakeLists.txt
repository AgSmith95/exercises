set(SOURCE_FILES main.cpp)
set(SOURCE_FILES2 tshev_solution.cpp)
set(EXECUTABLE task_alice_52_cards)
set(EXECUTABLE2 task_alice_52_cards_tshev)
add_executable(${EXECUTABLE} ${SOURCE_FILES})
add_executable(${EXECUTABLE2} ${SOURCE_FILES2})

if(MSVC)
  target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
else()
  target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
