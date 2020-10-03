#pragma once
#include <vector>
#include <utility>
#include "vertex.hpp"

namespace laf {
    class geometry final {
    public:
        geometry() = delete;
        ~geometry() = delete;



        /**
         * @brief Generates a vertices-indices pair of data for drawing a cube. Hard-coded base color.
         * 
         * @param edge normalized length of each edge, clamped to [.1, 1.0]
         * @return std::pair<std::vector<vertex> vertices, std::vector<unsigned int> indices> data
         */
        static std::pair<std::vector<vertex>, std::vector<unsigned int>> gen_sample_cube(float edge);
        


        /**
         * @brief Generates a vertices-indices pair of a square-based sphere, mostly used for testing. Hard-coded base color.
         * 
         * @param radius normalized radius, clamped to [.1, 1.0]
         * @param sectors number of sectors, clamped to [6, 100]
         * @param stacks number of stacks, clamped to [3, 100]
         * @return std::pair<std::vector<vertex> vertices, std::vector<unsigned int> indices> data
        */
        static std::pair<std::vector<vertex>, std::vector<unsigned int>> gen_sample_sphere(float radius, unsigned int sectors, unsigned int stacks);
    };
};