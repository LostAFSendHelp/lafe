#pragma once
#include <vector>
#include <vertex.hpp>

namespace laf {
    class model {
    public:
        const unsigned int id_;
        bool is_light_source_; // currently only means the model's color is rendered as-is

        model();
        virtual ~model();

        virtual void rotate(float radians, const glm::vec3& axis, bool normalized);
        virtual void translate(const glm::vec3& translation);

        inline const glm::mat4& rotation() const { return rotation_; }
        inline const glm::mat4& translation() const { return translation_; }

        inline static unsigned int count() { return count_; }

    private:
        static unsigned int count_;
        glm::mat4 rotation_{ 1.0f };
        glm::mat4 translation_{ 1.0f };
    };
};