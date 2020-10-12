#pragma once
#include <optional>
#include "gl_array_buffer.hpp"
#include "gl_index_buffer.hpp"

namespace laf {
    class gl_vao {
    public:
        gl_vao();
        ~gl_vao();

        void bind() const;
        void unbind() const;
        void update_data();

        template<typename T>
        void gen_buffer();
        template<typename T>
        void push(const T& data);

        inline GLuint id() const { return id_; }
        inline uint32_t index_count() const { return i_buffer_->index_count(); }
        inline uint32_t vertex_count() const { return a_buffer_->vertex_count(); }

    private:
        GLuint id_;
        std::optional<gl_array_buffer> a_buffer_;
        std::optional<gl_index_buffer> i_buffer_;
    };

    template<>
    void gl_vao::gen_buffer<gl_array_buffer>();

    template<>
    void gl_vao::gen_buffer<gl_index_buffer>();

    template<>
    void gl_vao::push<uint32_t>(const uint32_t& data);

    template<>
    void gl_vao::push<std::vector<uint32_t>>(const std::vector<uint32_t>& data);

    template<>
    void gl_vao::push<vertex>(const vertex& data);

    template<>
    void gl_vao::push<std::vector<vertex>>(const std::vector<vertex>& data);
};