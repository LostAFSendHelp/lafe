#include <input_manager.hpp>
#include <render_manager.hpp>
#include <gl_window.hpp>
#include <memory>
#include <iostream>

int main() {

    // setup
    std::unique_ptr<laf::window> window{ new laf::gl_window{ } };
    window->init();
    std::shared_ptr<laf::camera> camera{ new laf::camera{ } };
    
    laf::input_manager::init<laf::gl_input>();
    laf::render_manager::init<laf::gl_renderer>();
    laf::render_manager::make_camera_current(camera);

    std::vector<laf::vertex> vertices {
        {{-.25f, .25f, .25f }, { 0.0f, 0.0f, 1.0f }},     // TLF
        {{ .25f, .25f, .25f }, { 1.0f, 0.0f, 0.0f }},     // TRF
        {{ .25f, -.25f, .25f }, { 1.0f, 1.0f, 0.0f }},     // BRF
        {{-.25f, -.25f, .25f }, { 0.0f, 1.0f, 0.0f }},     // BLF
        
        {{-.25f, .25f, -.25f }, { 0.0f, 0.0f, 1.0f }},    // TLB
        {{ .25f, .25f, -.25f }, { 1.0f, 0.0f, 0.0f }},    // TRB
        {{ .25f, -.25f, -.25f }, { 1.0f, 1.0f, 0.0f }},    // BRB
        {{-.25f, -.25f, -.25f }, { 0.0f, 1.0f, 0.0f }}     // BLB
    };

    std::vector<unsigned int> indices {
        // front
        0, 1, 2,
        2, 3, 0,
        // right
        1, 5, 6,
        6, 2, 1,
        // back
        7, 6, 5,
        5, 4, 7,
        // left
        4, 0, 3,
        3, 7, 4,
        // bottom
        4, 5, 1,
        1, 0, 4,
        // top
        3, 2, 6,
        6, 7, 3
    };

    laf::render_manager::gen_model(vertices, indices);
    
    // main loop
    while(!window->is_open()) {
        window->update();
        window->wait_for_exit();

        laf::input_manager::poll_input(window.get());
        
        laf::render_manager::render();

        laf::input_manager::reset();
    }

    laf::render_manager::terminate();
    window->terminate();

    return 0;
}