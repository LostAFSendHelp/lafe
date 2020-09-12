cmake_minimum_required(VERSION 3.17)

# basic setups
project(lafe)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# functions
macro(search find_name modes)
    message(STATUS "- Searching for package [${find_name}]")
    find_package(${find_name} ${modes})
    if (${find_name}_FOUND)
        message(STATUS "--> Package found: [${find_name}]")
    else()
        message(FATAL_ERROR "--> Package not found: [${find_name}]")
    endif()
endmacro()

message(STATUS "Searching for required packages")
search(glfw3 CONFIG REQUIRED)
search(glm CONFIG REQUIRED)
search(GLEW REQUIRED)

# Subdirectories
add_subdirectory(src/input)
add_subdirectory(src/window)
add_subdirectory(src/renderer)

# Executables
add_executable(lafe-program src/lafe-program.cpp)

# linkage
target_link_libraries(lafe-program PRIVATE laf-input laf-window laf-renderer)