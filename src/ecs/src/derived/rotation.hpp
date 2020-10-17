#pragma once
#include "../component.hpp"

namespace laf {
    class rotation : public component {
    public:
        rotation();
        ~rotation();

        void awake() override;
        void update() override;

    private:
    };
};