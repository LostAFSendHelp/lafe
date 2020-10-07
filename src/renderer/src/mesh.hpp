#pragma once
#include <vector>
#include <vertex.hpp>

namespace laf {
    class mesh {
    public:
        const uint32_t id_;
        bool is_light_source_; // currently only means the mesh's color is rendered as-is

        mesh();
        virtual ~mesh();

        virtual void rotate(float radians, const glm::vec3& axis, bool normalized);
        virtual void translate(const glm::vec3& translation);

        inline const glm::mat4& rotation() const { return rotation_; }
        inline const glm::mat4& translation() const { return translation_; }
        inline glm::mat4 model() const { return translation_ * rotation_; }

        inline static uint32_t count() { return count_; }

    private:
        static uint32_t count_;
        glm::mat4 rotation_{ 1.0f };
        glm::mat4 translation_{ 1.0f };
    };
};