#pragma once
#include <vector>
#include <vertex.hpp>
#include "gl_vertex_buffer.hpp"

namespace laf {
    class gl_array_buffer : public gl_vertex_buffer {
    public:
        gl_array_buffer();
        ~gl_array_buffer();

        void update_data() const override;
        void push(const vertex& vertex);
        void push(const std::vector<vertex>& vertices, bool clear);

    private:
        std::vector<float> vertices_;
    };
};