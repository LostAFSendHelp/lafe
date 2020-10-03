#ifdef __DEBUG__
    #include <iostream>
#endif

#include "geometry.hpp"

namespace laf {
    std::pair<std::vector<float>, std::vector<unsigned int>> geometry::gen_sample_cube(float edge) {
        #ifdef __DEBUG__
            std::cout << "CALLING " << __func__ << std::endl;
        #endif

        

        return { };
    }

    std::pair<std::vector<float>, std::vector<unsigned int>> geometry::gen_sample_sphere(float radius, unsigned int sectors, unsigned int stacks) {
        #ifdef __DEBUG__
            std::cout << "CALLING " << __func__ << std::endl;
        #endif

        return { };
    }
}