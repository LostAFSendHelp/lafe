#pragma once
#include <vector>
#include "vertex.hpp"

namespace laf {
    class geometry final {
    public:
        geometry() = delete;
        ~geometry() = delete;



        /**
         * @brief Generates a vertices-indices pair of data for drawing a cube. Hard-coded base color.
         * 
         * @param edge Normalized length of each edge, clamped to [.1, 1.0]
         * @return std::vector<vertex>
         */
        static std::vector<vertex> gen_sample_cube(float edge);
        


        /**
         * @brief Generates a vertices-indices pair of a square-based sphere, mostly used for testing. Hard-coded base color.
         * 
         * @param radius Normalized radius, clamped to [.1, 1.0]
         * @param sectors Number of sectors, clamped to [6, 100]
         * @param stacks Number of stacks, clamped to [3, 100]
         * @return std::vector<vertex>
        */
        static std::vector<vertex> gen_sample_sphere(float radius, uint32_t sectors, uint32_t stacks, const glm::vec3& color);
    };
};