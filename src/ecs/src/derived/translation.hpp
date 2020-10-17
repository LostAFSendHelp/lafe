#pragma once
#include "../component.hpp"

namespace laf {
    class translation : public component {
    public:
        translation();
        ~translation();

        void awake() override;
        void update() override;

    private:
    };
};