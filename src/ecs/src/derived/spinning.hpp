#pragma once
#include "../component.hpp"

namespace laf {
    class spinning : public component {
    public:
        spinning();
        ~spinning();

        void awake() override;
        void update() override;
    private:
    };
};