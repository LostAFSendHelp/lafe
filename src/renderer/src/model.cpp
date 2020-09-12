#include <glm/gtc/matrix_transform.hpp>
#include "model.hpp"

namespace laf {
    unsigned int model::count_ = 0;

    model::model():
    id(count_++) {
        
    }

    model::~model() {
 
    }

    void model::rotate(float radians, const glm::vec3& axis, bool normalized) {
        rotation_ = glm::rotate(rotation_,
                                radians,
                                normalized ? glm::normalize(axis) : axis);
    }

    void model::translate(const glm::vec3& translation) {
        translation_ = glm::translate(translation_, translation);
    }
}