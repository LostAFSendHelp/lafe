#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace laf {
    class camera {
    public:
        camera();
        virtual ~camera();

        inline glm::vec3 right() const {
            return right_;
        }

        inline glm::vec3 up() const {
            return up_;
        }

        inline glm::vec3 position() const {
            return position_;
        }

        inline glm::vec3 front() const {
            return front_;
        }

        inline glm::mat4 projection() const {
            return projection_;
        }

        inline glm::mat4 view() const {
            return view_;
        }

        void set_fov(float radians);
        void set_front(const glm::vec3& front);
        void set_position(const glm::vec3& position);
        
    private:
        static const glm::vec3 BASE_UP;
        // TODO: this is for debugging only, change this sometime later
        static const float ASPECT;
        static const float NEAR;
        static const float FAR;
        float fov_;
        
        glm::vec3 position_;
        glm::vec3 last_position_;
        glm::vec3 front_;
        glm::vec3 last_front_;

        glm::vec3 right_;
        glm::vec3 up_;
        glm::mat4 projection_;
        glm::mat4 view_;
        
        inline void update_up() {
            up_ = glm::normalize(glm::cross(-front_, right_));
        }

        inline void update_right() {
            right_ = glm::normalize(glm::cross(BASE_UP, -front_));
        }

        inline void update_view() {
            view_ = glm::lookAt(position_, position_ + front_, up_);
        }
    };
};