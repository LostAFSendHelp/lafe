cmake_minimum_required(VERSION 3.17)

# Basic setups
project(lafe)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Functions
macro(config_macros target)
    target_compile_definitions(${target}
        PRIVATE $<$<CONFIG:DEBUG>:__DEBUG__>
                $<$<CONFIG:RELEASE>:__RELEASE__>)
endmacro()

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
add_subdirectory(src/geometry)
add_subdirectory(src/input)
add_subdirectory(src/window)
add_subdirectory(src/renderer)
add_subdirectory(src/ecs)

# Executables
add_executable(lafe-program src/lafe-program.cpp)

# Configs
config_macros(lafe-program)

# Linkage
target_link_libraries(lafe-program PRIVATE laf-geometry laf-input laf-window laf-renderer laf-ecs glm)