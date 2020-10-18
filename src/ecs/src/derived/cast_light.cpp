#ifdef __DEBUG__
    #include <iostream>
#endif

#include "cast_light.hpp"

namespace laf {
    cast_light::cast_light():
    light_source(),
    component() {
        #ifdef __DEBUG__
            std::cout << "LIGHT SOURCE CREATED" << std::endl;
        #endif
    }

    cast_light::~cast_light() {
        #ifdef __DEBUG__
            std::cout << "LIGHT SOURCE DESTROYED" << std::endl;
        #endif
    }

    void cast_light::awake() {
        if (auto _mesh = mesh()) {
            _mesh->is_light_source_ = true;
            color_ = _mesh->overlay_color_;
        }
    }

    void cast_light::update() {

    }

    glm::vec4 cast_light::world_location() const {
        if (auto _mesh = mesh()) {
            return mesh()->transform()->model() * location_;
        }

        return location_;
    }
}