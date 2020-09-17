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
        void update_data() const;

        template<typename T>
        void gen_buffer();
        template<typename T>
        void push(const T& data);

        inline GLuint id() const { return id_; }
        inline unsigned int index_count() const { return i_buffer_->count(); }

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
    void gl_vao::push<unsigned int>(const unsigned int& data);

    template<>
    void gl_vao::push<std::vector<unsigned int>>(const std::vector<unsigned int>& data);

    template<>
    void gl_vao::push<vertex>(const vertex& data);

    template<>
    void gl_vao::push<std::vector<vertex>>(const std::vector<vertex>& data);
};