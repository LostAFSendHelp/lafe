add_library(
    laf-input
    
    src/input.hpp
    src/input.cpp
    src/input_impl.hpp
    src/input_impl.cpp

    src/input_item.hpp
    src/input_item.cpp
)

target_link_libraries(laf-input PRIVATE glfw laf-window)
target_include_directories(laf-input PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)