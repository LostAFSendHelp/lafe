#pragma once
#include <vector>
#include "gl_vertex_buffer.hpp"

namespace laf {
    class gl_index_buffer : public gl_vertex_buffer {
    public:
        gl_index_buffer();
        ~gl_index_buffer();

        void update_data() const override;
        void push(uint32_t index);
        void push(const std::vector<uint32_t>& indices, bool clear);

        inline uint32_t count() const { return indices_.size(); }

    private:
        std::vector<uint32_t> indices_;
    };
};