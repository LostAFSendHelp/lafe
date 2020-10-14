#include <glm/gtc/matrix_transform.hpp>
#include "mesh.hpp"

namespace laf {
    uint32_t mesh::count_ = 0;

    mesh::mesh():
    id_(count_++),
    is_light_source_(false),
    transform_(new transform{ }) {
        
    }

    mesh::~mesh() {

    }
}