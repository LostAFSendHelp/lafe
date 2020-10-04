#ifdef __DEBUG__
    #include <iostream>
#endif

#include <glm/gtc/constants.hpp>
#include "geometry.hpp"

namespace laf {
    std::pair<std::vector<vertex>, std::vector<unsigned int>> geometry::gen_sample_cube(float edge) {
        #ifdef __DEBUG__
            std::cout << "CALLING " << __func__ << std::endl;
        #endif

        const auto MIN = .1f;
        const auto MAX = 1.0f;
        auto _abs_location = glm::clamp(edge, MIN, MAX) / 2;

        std::vector<laf::vertex> vertices {
            {{-_abs_location, _abs_location, _abs_location }, { 0.0f, 0.0f, 1.0f }},     // TLF
            {{ _abs_location, _abs_location, _abs_location }, { 1.0f, 0.0f, 0.0f }},     // TRF
            {{ _abs_location, -_abs_location, _abs_location }, { 1.0f, 1.0f, 0.0f }},     // BRF
            {{-_abs_location, -_abs_location, _abs_location }, { 0.0f, 1.0f, 0.0f }},     // BLF

            {{-_abs_location, _abs_location, -_abs_location }, { 0.0f, 0.0f, 1.0f }},    // TLB
            {{ _abs_location, _abs_location, -_abs_location }, { 1.0f, 0.0f, 0.0f }},    // TRB
            {{ _abs_location, -_abs_location, -_abs_location }, { 1.0f, 1.0f, 0.0f }},    // BRB
            {{-_abs_location, -_abs_location, -_abs_location }, { 0.0f, 1.0f, 0.0f }}     // BLB
        };

        std::vector<unsigned int> indices {
            // front
            0, 1, 2,
            2, 3, 0,
            // right
            1, 5, 6,
            6, 2, 1,
            // back
            7, 6, 5,
            5, 4, 7,
            // left
            4, 0, 3,
            3, 7, 4,
            // bottom
            4, 5, 1,
            1, 0, 4,
            // top
            3, 2, 6,
            6, 7, 3
        };

        return { vertices, indices };
    }

    std::pair<std::vector<vertex>, std::vector<unsigned int>> geometry::gen_sample_sphere(float radius, unsigned int sectors, unsigned int stacks) {
        #ifdef __DEBUG__
            std::cout << "CALLING " << __func__ << std::endl;
        #endif

        // clamp inputs
        const unsigned int MIN_SECTORS = 3;
        const unsigned int MAX_SECTORS = 100;

        const unsigned int MIN_STACKS = 6;
        const unsigned int MAX_STACKS = 100;

        const float MIN_RADIUS = .1f;
        const float MAX_RADIUS = 1.0f;

        auto _sectors = glm::clamp(sectors, MIN_SECTORS, MAX_SECTORS);
        auto _stacks = glm::clamp(stacks, MIN_STACKS, MAX_STACKS);
        auto _radius = glm::clamp(radius, MIN_RADIUS, MAX_RADIUS);

        std::vector<vertex> _vertices{ };
        std::vector<unsigned int> _indices{ };

        // north pole
        _vertices.push_back({
            { .0f, _radius, .0f },
            { .0f, 1.0f, .0f },
        });

        for (unsigned int _cur_sector = 1; _cur_sector < _sectors; ++_cur_sector) {
            auto _roll = glm::half_pi<float>() - glm::pi<float>() * ((float)_cur_sector / (float)_sectors); // drawing top-down
            auto _y = _radius * glm::sin(_roll);

            auto _top_anchor = (_cur_sector - 1) * _stacks + 1;
            auto _bottom_anchor = _top_anchor + _stacks;

            for (unsigned int _cur_stack = 0; _cur_stack < _stacks; ++_cur_stack, ++_top_anchor, ++_bottom_anchor) {
                
                // add vertex
                auto _yaw = glm::pi<float>() * 2.0f * ((float)_cur_stack / (float)_stacks);
                auto _x = _radius * glm::cos(_roll) * glm::sin(_yaw);
                auto _z = _radius * glm::cos(_roll) * glm::cos(_yaw);

                _vertices.push_back({
                    { _x, _y, _z, },
                    { glm::abs(_x) / _radius, glm::abs(_y) / _radius, glm::abs(_z) / _radius }
                });

                // add indices
                auto _top_next = (_top_anchor % _stacks == 0) ? ((_cur_sector - 1) * _stacks + 1) : (_top_anchor + 1); // draw through first point in sector if current point is last of sector
                auto _bottom_next = _top_next + _stacks;
                
                if (_cur_sector == 1) {
                    _indices.push_back(0); // index of north pole
                    _indices.push_back(_top_anchor);
                    _indices.push_back(_top_next);
                }

                if (_cur_sector < _sectors - 1) {
                    _indices.push_back(_top_anchor);
                    _indices.push_back(_bottom_anchor);
                    _indices.push_back(_bottom_next);

                    _indices.push_back(_top_anchor);
                    _indices.push_back(_bottom_next);
                    _indices.push_back(_top_next);
                } else {
                    _indices.push_back(_top_anchor);
                    _indices.push_back((_sectors - 1) * _stacks + 1); // index of south pole
                    _indices.push_back(_top_next);
                }
            }
        }
        
        // south pole
        _vertices.push_back({
            { .0f, -_radius, .0f },
            { .0f, 1.0f, .0f },
        });

        #ifdef __DEBUG__
            std::cout << "Vertices count " << _vertices.size() << std::endl;
        #endif

        return { _vertices, _indices };
    }
}