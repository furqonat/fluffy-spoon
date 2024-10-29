cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(OpenGLProject VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories for GLFW and GLAD
include_directories(libs/glfw/include libs/glad/include src)

# Find and link OpenGL
find_package(OpenGL REQUIRED)

# Add GLFW as a library
add_subdirectory(libs/glfw)

# Add GLAD source files
add_library(glad STATIC libs/glad/src/glad.c)

# Link GLAD with the OpenGL libraries
target_link_libraries(glad ${OPENGL_LIBRARIES})

# Include the source files from the src directory
file(GLOB SRC_FILES 
    src/*.cpp
    src/scene/*.cpp
    src/core/*.cpp
    src/ui/*.cpp
)

# Add the executable target
add_executable(OpenGLProject main.cpp ${SRC_FILES})

# Link libraries
target_link_libraries(OpenGLProject glfw glad ${OPENGL_LIBRARIES})
