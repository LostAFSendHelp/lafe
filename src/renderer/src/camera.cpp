#include <glm/gtc/matrix_transform.hpp>
#include "render_manager.hpp"
#include "camera.hpp"

namespace laf {
    const glm::vec3 camera::BASE_UP{ .0f, 1.0f, .0f };
    const float camera::ASPECT = 800.0f / 600.0f;
    const float camera::NEAR = .1f;
    const float camera::FAR = 100.0f;

    camera::camera():
    position_(.0f, 1.0f, 3.0f),
    last_position_(position_),
    front_(.0f, .0f, -1.0f),
    last_front_(front_),
    right_(glm::normalize(glm::cross(BASE_UP, position_ - front_))),
    up_(glm::normalize(glm::cross(position_ - front_, right_))),
    fov_(glm::radians(45.0f)),
    projection_(glm::perspective(fov_, ASPECT, NEAR, FAR)),
    view_(glm::lookAt(position_, position_ + front_, up_)) {

    }

    camera::~camera() {

    }

    void camera::set_fov(float radians) {
        fov_ = radians;
        projection_ = glm::perspective(fov_, ASPECT, NEAR, FAR);
    }

    void camera::set_front(const glm::vec3& front) {
        if (front_ != front) {
            front_ = front;
            update_axes();
        }
    }

    void camera::set_position(const glm::vec3& position) {
        if (position_ != position){
            position_ = position;
            update_axes();
        }
    }

    void camera::update_axes() {
        right_ = glm::normalize(glm::cross(BASE_UP, front_));
        up_ = glm::normalize(glm::cross(front_, right_));
        view_ = glm::lookAt(position_, position_ + front_, up_);
    }
}