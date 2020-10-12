#include "vertex.hpp"

namespace laf {
    std::size_t vertex::size_position() {
        return 3;
    }

    std::size_t vertex::size_normal() {
        return 3;
    }

    std::size_t vertex::size_vertex() {
        return 6;
    }
}