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
        bool is_open() const override;
        void wait_for_exit() override;
        void terminate() override;
        void toggle_cursor(bool on) override;

        int get_key(int key) const override;
        std::pair<double, double> cursor_location() const override;
    
    private:
        GLFWwindow* window_;
        static const int WIDTH;
        static const int HEIGHT;
        static const char* TITLE;
    };
};