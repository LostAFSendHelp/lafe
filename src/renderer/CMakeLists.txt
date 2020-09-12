add_library(
    laf-renderer

    src/model.hpp
    src/model.cpp
    src/renderer.hpp
    src/renderer.cpp
    src/vertex.hpp
    src/vertex.cpp
    src/render_manager.hpp
    src/render_manager.cpp
    src/camera.hpp
    src/camera.cpp

    src/gl/src/data/gl_array_buffer.hpp
    src/gl/src/data/gl_array_buffer.cpp
    src/gl/src/data/gl_index_buffer.hpp
    src/gl/src/data/gl_index_buffer.cpp
    src/gl/src/data/gl_model.hpp
    src/gl/src/data/gl_model.cpp
    src/gl/src/data/gl_vao.hpp
    src/gl/src/data/gl_vao.cpp
    src/gl/src/data/gl_vertex_buffer.hpp
    src/gl/src/data/gl_vertex_buffer.cpp
    
    src/gl/src/render/gl_program.hpp
    src/gl/src/render/gl_program.cpp
    src/gl/src/render/gl_renderer.hpp
    src/gl/src/render/gl_renderer.cpp
    src/gl/src/render/gl_shader.hpp
    src/gl/src/render/gl_shader.cpp
)

target_link_libraries(laf-renderer PUBLIC GLEW::GLEW glm)
target_include_directories(laf-renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)