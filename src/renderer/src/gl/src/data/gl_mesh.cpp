#include "gl_mesh.hpp"

namespace laf {
    gl_mesh::gl_mesh(const std::vector<vertex>& vertices):
    mesh(),
    vao_() {
        if (vertices.empty()) return;
        vao_.bind();

        vao_.gen_buffer<gl_array_buffer>();
        vao_.push(vertices);

        vao_.update_data();
        vao_.unbind();
    }

    gl_mesh::~gl_mesh() {

    }
}