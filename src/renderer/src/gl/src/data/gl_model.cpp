#include "gl_model.hpp"

namespace laf {
    gl_model::gl_model(const std::vector<vertex>& vertices, const std::vector<unsigned int>& indices):
    model(),
    vao_() {
        vao_.bind();

        vao_.gen_buffer<gl_array_buffer>();
        vao_.push(vertices);
        vao_.gen_buffer<gl_index_buffer>();
        vao_.push(indices);

        vao_.update_data();
        vao_.unbind();
    }

    gl_model::~gl_model() {

    }
}