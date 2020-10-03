#include "vertex.hpp"

namespace laf {
    std::size_t vertex::size_position() {
        return 3;
    }

    std::size_t vertex::size_color() {
        return 3;
    }

    std::size_t vertex::size_vertex() {
        return 6;
    }
}