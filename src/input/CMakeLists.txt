add_library(
    laf-input
    
    src/input.hpp
    src/input.cpp

    src/gl_input.hpp
    src/gl_input.cpp

    src/input_item.hpp
    src/input_item.cpp

    src/input_manager.hpp
    src/input_manager.cpp
)

target_link_libraries(laf-input PUBLIC glfw laf-window)
target_include_directories(laf-input PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
config_macros(laf-input)