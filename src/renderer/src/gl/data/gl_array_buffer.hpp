#pragma once
#include <vector>
#include <vertex.hpp>
#include "gl_vertex_buffer.hpp"

namespace laf {
    class gl_array_buffer : public gl_vertex_buffer {
    public:
        gl_array_buffer();
        ~gl_array_buffer();

        void update_data() override;
        void push(const vertex& vertex);
        void push(const std::vector<vertex>& vertices, bool clear);

        inline uint32_t vertex_count() const { return vertex_count_; }

    private:
        std::vector<float> vertices_;
        uint32_t vertex_count_;
    };
};