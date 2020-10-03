#include "gl_array_buffer.hpp"

namespace laf {
    gl_array_buffer::gl_array_buffer():
    gl_vertex_buffer(GL_ARRAY_BUFFER) {

    }

    gl_array_buffer::~gl_array_buffer() {

    }

    void gl_array_buffer::update_data() const {
        bind();
        glBufferData(type, sizeof(float) * vertices_.size(), &vertices_[0], GL_STATIC_DRAW);
        
        glVertexAttribPointer(0, vertex::size_position(), GL_FLOAT, GL_FALSE, sizeof(float) * vertex::size_vertex(), nullptr);
        glVertexAttribPointer(1, vertex::size_color(), GL_FLOAT, GL_FALSE, sizeof(float) * vertex::size_vertex(), (void*)(sizeof(float) * vertex::size_position()));
        
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
    }

    void gl_array_buffer::push(const vertex& vertex) {
        vertices_.push_back(vertex.position.x);
        vertices_.push_back(vertex.position.y);
        vertices_.push_back(vertex.position.z);

        vertices_.push_back(vertex.color.x);
        vertices_.push_back(vertex.color.y);
        vertices_.push_back(vertex.color.z);
    }

    void gl_array_buffer::push(const std::vector<vertex>& vertices, bool clear) {
        if (clear) {
            vertices_.clear();
        }
        
        for (const auto& vertex : vertices) {
            push(vertex);
        }
    }
}