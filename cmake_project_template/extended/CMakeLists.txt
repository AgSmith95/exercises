# At LEAST 2.8 but newer is better
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(myproject VERSION 0.1 LANGUAGES CXX)

# Must use GNUInstallDirs to install libraries into correct
# locations on all platforms.
include(GNUInstallDirs)

# Include Boost as an imported target
# find_package(Boost REQUIRED)
# add_library(boost INTERFACE IMPORTED)
# set_property(TARGET boost PROPERTY
#         INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})

# Some other library that we import that was also built using CMake
# and has an exported target.
# find_package(someLib REQUIRED)

# Targets that we develop here
enable_testing()
add_subdirectory(lib)
add_subdirectory(app)