#pragma once
#include <glm/glm.hpp>

namespace laf {
    class light_source {
    public:
        light_source(const glm::vec3& location = glm::vec3{ .0f, 4.0f, -4.0f },
                     const glm::vec3& color = glm::vec3{ 1.0f },
                     float ambient = .5f);
        ~light_source();

        glm::vec3 location_;
        glm::vec3 color_;
        float ambient_;
    private:
    };
};