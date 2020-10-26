#include <iostream>
#include <GL/glew.h>
#include "gl_window.hpp"

namespace laf {
    const int gl_window::WIDTH = 800;
    const int gl_window::HEIGHT = 600;
    const char* gl_window::TITLE = "GL";
    
    gl_window::gl_window():
    window(),
    key_down_([](int key) { }),
    is_cursor_enabled_(false) {

    }

    gl_window::~gl_window() {

    }

    void gl_window::init() {
        glfwSetErrorCallback([](int code, const char* message) {
            std::cout << "GL_WINDOW ERROR ["
                      << code
                      << "] : "
                      << message
                      << std::endl;
        });

        glfwInit();
        glfwWindowHint(GLFW_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_VERSION_MINOR, 3);
        window_ = glfwCreateWindow(WIDTH, HEIGHT, TITLE, nullptr, nullptr);
        glfwMakeContextCurrent(window_);
        glfwSetWindowUserPointer(window_, this);
        glfwSetKeyCallback(window_, [](GLFWwindow* w, int key, int scancode, int action, int mods) {
            if (auto _ptr = static_cast<gl_window*>(glfwGetWindowUserPointer(w))) {
                if (action == GLFW_PRESS) _ptr->key_down_(key);
            }
        });
        
        glewInit();
        std::cout << "OPENGL version: " << glGetString(GL_VERSION) << std::endl;
        glViewport(0, 0, WIDTH, HEIGHT);
        glEnable(GL_DEPTH_TEST);
    }

    void gl_window::update() {
        glfwSwapBuffers(window_);
        glfwPollEvents();
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    bool gl_window::is_open() const {
        return glfwWindowShouldClose(window_);
    }

    void gl_window::wait_for_exit() {
        // TODO: think of a more comprehensible way to exit
        if (get_key(GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(window_, GLFW_TRUE);
        }
    }

    void gl_window::terminate() {
        glfwTerminate();
    }

    void gl_window::toggle_cursor(bool on) {
        auto mode = on ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED;
        glfwSetInputMode(window_, GLFW_CURSOR, mode);
        glfwSetCursorPos(window_, gl_window::WIDTH / 2.0f, gl_window::HEIGHT / 2.0f);
        is_cursor_enabled_ = on;
    }

    void gl_window::key_down_callback(const std::function<void(int)>& callback) {
        key_down_ = callback;
    }

    int gl_window::get_key(int key) const {
        return glfwGetKey(window_, key);
    }

    bool gl_window::is_cursor_enabled() const {
        return is_cursor_enabled_;
    }

    std::pair<double, double> gl_window::cursor_location() const {
        double x, y;
        glfwGetCursorPos(window_, &x, &y);
        return { x, y };
    }
}