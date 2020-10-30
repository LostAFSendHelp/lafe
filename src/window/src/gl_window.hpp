#pragma once
#include "window.hpp"
#include <GLFW/glfw3.h>

namespace laf {
    class gl_window : public window {
    public:
        gl_window();
        ~gl_window();

        void init() override;
        void update() override;

    private:

    };
};