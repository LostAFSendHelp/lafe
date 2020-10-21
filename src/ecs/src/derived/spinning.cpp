#include "spinning.hpp"

namespace laf {
    spinning::spinning() {

    }

    spinning::~spinning() {

    }

    void spinning::awake() {

    }

    void spinning::update() {
        if (auto _mesh = this->mesh()) {
            _mesh->transform()->rotate(.0025f, glm::vec3{ .0f, 1.0f, .0f }, false, true);
        }
    }
}