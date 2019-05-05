# Define library. Only source files here!
cmake_minimum_required(VERSION 3.10)

project(lib VERSION 0.1)

# set_source_files_properties(src/lib.cpp PROPERTIES LANGUAGE CXX)
add_library(lib STATIC
        src/lib.cpp)

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
target_include_directories(lib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)

# If we have compiler requirements for this library, list them
# here
# target_compile_features(lib
#         PUBLIC cxx_auto_type
#         PRIVATE cxx_variadic_templates)

# Depend on a library that we defined in the top-level file
# target_link_libraries(lib
#         someLib)

# 'make install' to the correct locations (provided by GNUInstallDirs).
install(TARGETS lib EXPORT lib_cfg
        ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# This makes the project importable from the install directory
# Put config file in per-project dir (name MUST match), can also
# just go into 'cmake'.
install(EXPORT lib_cfg DESTINATION share/lib/cmake)

# This makes the project importable from the build directory
export(TARGETS lib FILE lib_cfg.cmake)


# Every library has unit tests, of course
add_executable(lib_test
        test/lib_test.cpp)

target_link_libraries(lib_test
        lib)

add_test(lib_test lib_test)
