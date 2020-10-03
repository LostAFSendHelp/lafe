#pragma once
#include <glm/glm.hpp>

namespace laf {
    struct vertex {
        glm::vec3 position;
        glm::vec3 color;

        static std::size_t size_position();
        static std::size_t size_color();
        static std::size_t size_vertex();
    };
};