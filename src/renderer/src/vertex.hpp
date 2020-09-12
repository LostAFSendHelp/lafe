#pragma once
#include <glm/glm.hpp>

namespace laf {
    struct vertex {
        glm::vec3 position;
        glm::vec3 color;

        static const std::size_t SIZE_POSITION;
        static const std::size_t SIZE_COLOR;
        static const std::size_t SIZE_VERTEX;
    };
};