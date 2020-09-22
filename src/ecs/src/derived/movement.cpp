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
        if (auto model = this->model()) {
            model->rotate(.005f, { .0f, 1.0f, .0f }, false);
            auto h = input_manager::get_input("leftright");
            auto v = input_manager::get_input("updown");

            glm::vec3 translation{ .005f * h, .0f, -.005f * v };
            model->translate(translation);
        }

    }
}