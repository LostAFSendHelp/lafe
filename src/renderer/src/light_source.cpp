#ifdef __DEBUG__
    #include <iostream>
#endif

#include "light_source.hpp"

namespace laf {
    light_source::light_source(const glm::vec3& location, const glm::vec3& color, float ambient):
    location_(location),
    color_(color),
    ambient_(ambient) {
        #ifdef __DEBUG__
            std::cout << "LIGHT SOURCE INITIALIZED" << std::endl;
        #endif
    }

    light_source::~light_source() {
        #ifdef __DEBUG__
            std::cout << "LIGHT SOURCE DESTROYED" << std::endl;
        #endif
    }
}