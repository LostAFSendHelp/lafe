add_library(
    laf-window
    src/window.hpp
    src/window.cpp
    src/gl_window.hpp
    src/gl_window.cpp
)

target_link_libraries(laf-window PUBLIC glfw GLEW::GLEW)
target_include_directories(laf-window PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
config_macros(laf-window)