#include "gl_mesh.hpp"

namespace laf {
    gl_mesh::gl_mesh(const std::vector<vertex>& vertices, const std::vector<uint32_t>& indices):
    mesh(),
    vao_() {
        vao_.bind();

        vao_.gen_buffer<gl_array_buffer>();
        vao_.push(vertices);
        vao_.gen_buffer<gl_index_buffer>();
        vao_.push(indices);

        vao_.update_data();
        vao_.unbind();
    }

    gl_mesh::~gl_mesh() {

    }
}