#include <input_manager.hpp>
#include "translation.hpp"

namespace laf {
    translation::translation():
    component() {

    }

    translation::~translation() {

    }

    void translation::awake() {

    }

    void translation::update() {
        if (auto _mesh = this->mesh()) {
            auto _horizontal = input_manager::get_input("leftright");
            auto _vertical = input_manager::get_input("updown");

            glm::vec3 _translation{ .005f * _horizontal, .0f, -.005f * _vertical };
            _mesh->transform_->translate(_translation, true);
        }

    }
}