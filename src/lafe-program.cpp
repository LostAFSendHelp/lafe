#include <glm/gtx/rotate_vector.hpp>
#include <input_manager.hpp>
#include <render_manager.hpp>
#include <gl_window.hpp>
#include <entity.hpp>
#include <derived/movement.hpp>
#include <memory>
#include <iostream>

int main() {

    // setup
    std::shared_ptr<laf::window> window{ new laf::gl_window{ } };
    window->init();
    std::shared_ptr<laf::camera> camera{ new laf::camera{ } };
    
    laf::input_manager::init<laf::gl_input>(window);
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

    auto model = laf::render_manager::gen_model(vertices, indices);
    auto entity = std::make_shared<laf::entity>();
    entity->add_model(model);
    auto movement = std::make_shared<laf::movement>();
    entity->add_component(movement);
    movement->attach(entity);

    entity->awake();
    laf::input_manager::toggle_cursor(false);
    
    // main loop
    while(!window->is_open()) {
        window->update();
        window->wait_for_exit();

        laf::input_manager::poll_input();

        // TODO: this is for testing only, remove when done
        {
            entity->update();

            static const float TURN_RATE = .0004f;
            auto front = camera->front();
            auto right = camera->right();
            auto cursor_axes = laf::input_manager::cursor_axes(false);
            auto rotation_x = (float)cursor_axes.second * TURN_RATE * -1;
            auto rotation_y = (float)cursor_axes.first * TURN_RATE * -1;
            front = glm::rotate(front, rotation_x, right);
            front = glm::rotateY(front, rotation_y);
            camera->set_front(front);

            // translate
            static const float SPEED = .01f;
            float horizontal = laf::input_manager::get_input("horizontal");
            float vertical = laf::input_manager::get_input("vertical");
            auto position = camera->position();
            auto transformation = vertical * camera->front() + horizontal * camera->right();
            if (transformation != glm::vec3{ .0f, .0f, .0f }) {
                position += SPEED * glm::normalize(transformation);
                camera->set_position(position);
            }

        }

        
        laf::render_manager::render();
    }

    laf::render_manager::terminate();
    window->terminate();

    return 0;
}