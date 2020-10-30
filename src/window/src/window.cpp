#include <iostream>
#include "window.hpp"

namespace laf {

    const int window::WIDTH = 800;
    const int window::HEIGHT = 600;
    const char* window::TITLE = "LAFE";

    window::window():
    key_down_([](int key) { }),
    is_cursor_enabled_(false) {

    }

    window::~window() {

    }

    void window::init() {
        glfwSetErrorCallback([](int code, const char* message) {
            std::cout << "WINDOW CREATION ERROR ["
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
            if (auto _ptr = static_cast<window*>(glfwGetWindowUserPointer(w))) {
                if (action == GLFW_PRESS) _ptr->key_down_(key);
            }
        });
    }

    void window::update() {
        glfwSwapBuffers(window_);
        glfwPollEvents();
    }

    bool window::is_open() const {
        return glfwWindowShouldClose(window_);
    }

    void window::wait_for_exit() {
        // TODO: think of a more comprehensible way to exit
        if (get_key(GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(window_, GLFW_TRUE);
        }
    }

    void window::terminate() {
        glfwTerminate();
    }

    void window::toggle_cursor(bool on) {
        auto mode = on ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED;
        glfwSetInputMode(window_, GLFW_CURSOR, mode);
        glfwSetCursorPos(window_, window::WIDTH / 2.0f, window::HEIGHT / 2.0f);
        is_cursor_enabled_ = on;
    }

    void window::key_down_callback(const std::function<void(int)>& callback) {
        key_down_ = callback;
    }

    int window::get_key(int key) const {
        return glfwGetKey(window_, key);
    }

    bool window::is_cursor_enabled() const {
        return is_cursor_enabled_;
    }

    std::pair<double, double> window::cursor_location() const {
        double x, y;
        glfwGetCursorPos(window_, &x, &y);
        return { x, y };
    }
}