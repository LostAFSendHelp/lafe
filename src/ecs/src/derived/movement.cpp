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
        if (auto _model = this->model()) {
            _model->rotate(.005f, { .0f, 1.0f, .0f }, false);
            auto _horizontal = input_manager::get_input("leftright");
            auto _vertical = input_manager::get_input("updown");

            glm::vec3 _translation{ .005f * _horizontal, .0f, -.005f * _vertical };
            _model->translate(_translation);
        }

    }
}