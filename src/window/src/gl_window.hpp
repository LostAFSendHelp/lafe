#pragma once
#include <GLFW/glfw3.h>
#include "window.hpp"

namespace laf {
    class gl_window : public window {
    public:
        gl_window();
        ~gl_window();

        void init() override;
        void update() override;
        bool is_open() const;
        void wait_for_exit() override;
        void terminate() override;
        int get_key(int key) const override;
    
    private:
        GLFWwindow* window_;
        static const int WIDTH;
        static const int HEIGHT;
        static const char* TITLE;
    };
};