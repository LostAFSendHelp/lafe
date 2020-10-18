#pragma once
#include <light_source.hpp>
#include "../component.hpp"

namespace laf {
    class cast_light final : public light_source, public component {
    public:
        cast_light();
        ~cast_light();

        void awake() override;
        void update() override;
        glm::vec4 world_location() const override;

    private:
    };
};