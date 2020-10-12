#pragma once
#include <glm/glm.hpp>

namespace laf {
    struct vertex {
        glm::vec3 position;
        glm::vec3 normal_;

        static std::size_t size_position();
        static std::size_t size_normal();
        static std::size_t size_vertex();
    };
};