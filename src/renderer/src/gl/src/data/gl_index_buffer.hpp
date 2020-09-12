#pragma once
#include <vector>
#include "gl_vertex_buffer.hpp"

namespace laf {
    class gl_index_buffer : public gl_vertex_buffer {
    public:
        gl_index_buffer();
        ~gl_index_buffer();

        void update_data() const override;
        void push(unsigned int index);
        void push(const std::vector<unsigned int>& indices, bool clear);

        inline unsigned int count() const { return indices_.size(); }

    private:
        std::vector<unsigned int> indices_;
    };
};