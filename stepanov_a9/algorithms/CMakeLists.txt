cmake_minimum_required(VERSION 3.10)
project(swap_min_search)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp)
set(EXECUTABLE swap_min_search)
add_executable(${EXECUTABLE} ${SOURCE_FILES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(benchmark REQUIRED)
set(BENCH_EXEC benchmarks)
set(BENCH_SRC bench.cpp)
add_executable(${BENCH_EXEC} ${BENCH_SRC})
target_link_libraries(
    ${BENCH_EXEC}
    Threads::Threads
    benchmark::benchmark
)

if(MSVC)
  target_compile_options(${EXECUTABLE} PRIVATE /W4 /WX)
  target_compile_options(${BENCH_EXEC} PRIVATE /W4 /WX)
else()
  target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
  target_compile_options(${BENCH_EXEC} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
