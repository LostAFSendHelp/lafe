#pragma once
#include <glm/glm.hpp>

namespace laf {
    class light_source {
    public:
        light_source(const glm::vec4& location = glm::vec4{ .0f, .0f, .0f, 1.0f },
                     const glm::vec3& color = glm::vec3{ 1.0f },
                     float ambient = .2f);
        virtual ~light_source();

        virtual glm::vec4 world_location() const;

        glm::vec4 location_;
        glm::vec3 color_;
        float ambient_;
    private:
    };
};