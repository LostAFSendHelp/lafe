#include "gl_index_buffer.hpp"

namespace laf {
    gl_index_buffer::gl_index_buffer():
    gl_vertex_buffer(GL_ELEMENT_ARRAY_BUFFER) {

    }

    gl_index_buffer::~gl_index_buffer() {

    }

    void gl_index_buffer::update_data() const {
        bind();
        glBufferData(type, sizeof(unsigned int) * indices_.size(), &indices_[0], GL_STATIC_DRAW);
    }

    void gl_index_buffer::push(unsigned int index) {
        indices_.push_back(index);
    }

    void gl_index_buffer::push(const std::vector<unsigned int>& indices, bool clear) {
        if (clear) {
            indices_ = indices;
        } else {
            for (const auto& index : indices) {
                push(index);
            }
        }
    }
}