#include "gl_vao.hpp"

namespace laf {
    gl_vao::gl_vao() {
        glGenVertexArrays(1, &id_);
    }

    gl_vao::~gl_vao() {

    }

    void gl_vao::bind() const {
        glBindVertexArray(id_);
    }

    void gl_vao::unbind() const {
        glBindVertexArray(0);
    }

    void gl_vao::update_data() const {
        bind();
        a_buffer_->update_data();
        i_buffer_->update_data();
    }

    template<>
    void gl_vao::gen_buffer<gl_index_buffer>() {
        if (i_buffer_.has_value()) return;
        i_buffer_.emplace();
    }

    template<>
    void gl_vao::gen_buffer<gl_array_buffer>() {
        if (a_buffer_.has_value()) return;
        a_buffer_.emplace();
    }

    template<>
    void gl_vao::push<uint32_t>(const uint32_t& data) {
        if (!i_buffer_.has_value()) return;
        i_buffer_->push(data);
    }

    template<>
    void gl_vao::push<std::vector<uint32_t>>(const std::vector<uint32_t>& data) {
        if (!i_buffer_.has_value()) return;
        i_buffer_->push(data, false);
    }

    template<>
    void gl_vao::push<vertex>(const vertex& data) {
        if (!a_buffer_.has_value()) return;
        a_buffer_->push(data);
    }

    template<>
    void gl_vao::push<std::vector<vertex>>(const std::vector<vertex>& data) {
        if (!a_buffer_.has_value()) return;
        a_buffer_->push(data, false);
    }
}