#include <glm/gtc/matrix_transform.hpp>
#include "mesh.hpp"

namespace laf {
    unsigned int mesh::count_ = 0;

    mesh::mesh():
    id_(count_++),
    is_light_source_(false) {
        
    }

    mesh::~mesh() {
 
    }

    void mesh::rotate(float radians, const glm::vec3& axis, bool normalized) {
        rotation_ = glm::rotate(rotation_,
                                radians,
                                normalized ? glm::normalize(axis) : axis);
    }

    void mesh::translate(const glm::vec3& translation) {
        translation_ = glm::translate(translation_, translation);
    }
}