#pragma once
#include <utility>
#include <functional>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace laf {
    class window {
    public:
        virtual ~window();

        virtual void init();
        virtual void update();
        virtual bool is_open() const;
        virtual void wait_for_exit();
        virtual void terminate();
        virtual void toggle_cursor(bool on);
        virtual void key_down_callback(const std::function<void(int)>& callback);
        
        virtual int get_key(int key) const;
        virtual bool is_cursor_enabled() const;
        virtual std::pair<double, double> cursor_location() const;

    protected:
        window();

        GLFWwindow* window_;
        static const int WIDTH;
        static const int HEIGHT;
        static const char* TITLE;
        std::function<void(int)> key_down_;
        bool is_cursor_enabled_;
    };
};