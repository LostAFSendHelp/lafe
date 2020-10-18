#include "rotation.hpp"
#include <input_manager.hpp>

namespace laf {
    rotation::rotation() {

    }

    rotation::~rotation() {

    }

    void rotation::awake() {

    }

    void rotation::update() {
        if (auto _mesh = this->mesh()) {
            auto _rotation = input_manager::get_input("rotate");
            _mesh->transform()->rotate(.005f * _rotation, { .0f, 1.0f, .0f }, false, true);
        }
    }
}