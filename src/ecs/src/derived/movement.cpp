#include <input_manager.hpp>
#include "movement.hpp"

namespace laf {
    movement::movement():
    component() {

    }

    movement::~movement() {

    }

    void movement::awake() {

    }

    void movement::update() {
        if (auto _mesh = this->mesh()) {
            auto _horizontal = input_manager::get_input("leftright");
            auto _vertical = input_manager::get_input("updown");
            auto _rotation = input_manager::get_input("rotate");

            glm::vec3 _translation{ .005f * _horizontal, .0f, -.005f * _vertical };
            _mesh->transform_->translate(_translation, false);
            _mesh->transform_->rotate(.005f * _rotation, { .0f, 1.0f, .0f }, false, true);
        }

    }
}