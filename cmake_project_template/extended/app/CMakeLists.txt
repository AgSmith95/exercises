# Define an executable
add_executable(app
        src/main.cpp)

# Define the libraries this project depends upon
target_link_libraries(app
        lib)