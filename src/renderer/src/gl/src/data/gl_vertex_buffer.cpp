#include "gl_vertex_buffer.hpp"

namespace laf {
    gl_vertex_buffer::gl_vertex_buffer(GLenum type):
    type(type) {
        glGenBuffers(1, &id_);
    }

    gl_vertex_buffer::~gl_vertex_buffer() {

    }

    void gl_vertex_buffer::bind() const {
        glBindBuffer(type, id_);
    }

    void gl_vertex_buffer::unbind() const {
        glBindBuffer(type, 0);
    }

    GLuint gl_vertex_buffer::id() const {
        return id_;
    }
}