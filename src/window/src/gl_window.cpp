#include <iostream>
#include <GL/glew.h>
#include "gl_window.hpp"

namespace laf {
    const int gl_window::WIDTH = 800;
    const int gl_window::HEIGHT = 600;
    const char* gl_window::TITLE = "GL";
    
    gl_window::gl_window():
    window() {

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

    int gl_window::get_key(int key) const {
        return glfwGetKey(window_, key);
    }
}