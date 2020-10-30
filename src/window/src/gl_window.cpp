#include <iostream>
#include <GL/glew.h>
#include "gl_window.hpp"

namespace laf {
    
    gl_window::gl_window():
    window() {

    }

    gl_window::~gl_window() {

    }

    void gl_window::init() {
        window::init();
        
        glewInit();
        std::cout << "OPENGL version: " << glGetString(GL_VERSION) << std::endl;
        glViewport(0, 0, WIDTH, HEIGHT);
        glEnable(GL_DEPTH_TEST);
    }

    void gl_window::update() {
        window::update();

        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}