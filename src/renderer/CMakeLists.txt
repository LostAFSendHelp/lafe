add_library(
    laf-renderer

    src/mesh.hpp
    src/mesh.cpp
    src/renderer.hpp
    src/renderer.cpp
    src/render_manager.hpp
    src/render_manager.cpp
    src/camera.hpp
    src/camera.cpp
    src/transform.hpp
    src/transform.cpp
    src/light_source.hpp
    src/light_source.cpp

    src/gl/data/gl_array_buffer.hpp
    src/gl/data/gl_array_buffer.cpp
    src/gl/data/gl_index_buffer.hpp
    src/gl/data/gl_index_buffer.cpp
    src/gl/data/gl_mesh.hpp
    src/gl/data/gl_mesh.cpp
    src/gl/data/gl_vao.hpp
    src/gl/data/gl_vao.cpp
    src/gl/data/gl_vertex_buffer.hpp
    src/gl/data/gl_vertex_buffer.cpp
    
    src/gl/render/gl_program.hpp
    src/gl/render/gl_program.cpp
    src/gl/render/gl_renderer.hpp
    src/gl/render/gl_renderer.cpp
    src/gl/render/gl_shader.hpp
    src/gl/render/gl_shader.cpp
)

target_link_libraries(laf-renderer PRIVATE laf-geometry GLEW::GLEW)
target_include_directories(laf-renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
add_custom_command(TARGET laf-renderer POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_CURRENT_SOURCE_DIR}/assets/ $<TARGET_FILE_DIR:laf-renderer>/assets)
config_macros(laf-renderer)