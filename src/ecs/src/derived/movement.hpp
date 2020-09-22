#pragma once
#include "../component.hpp"

namespace laf {
    class movement: public component {
    public:
        movement();
        ~movement();

        void awake() override;
        void update() override;

    private:
    };
};