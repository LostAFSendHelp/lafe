#include <glm/gtx/rotate_vector.hpp>
#include <input_manager.hpp>
#include <render_manager.hpp>
#include <gl_window.hpp>
#include <entity.hpp>
#include <derived/movement.hpp>
#include <geometry.hpp>
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

    auto sphere_model = laf::render_manager::gen_model(laf::geometry::gen_sample_sphere(.25f, 40, 60));
    auto sphere = std::make_shared<laf::entity>();
    sphere->add_model(sphere_model);
    std::shared_ptr<laf::component> sphere_movement = std::make_shared<laf::movement>();
    sphere->attach_component(sphere_movement);
    sphere->model()->translate({ -.5f, .0f, .0f });

    auto cube_model = laf::render_manager::gen_model(laf::geometry::gen_sample_cube(.5f));
    auto cube = std::make_shared<laf::entity>();
    cube->add_model(cube_model);
    std::shared_ptr<laf::component> cube_movement = std::make_shared<laf::movement>();
    cube->attach_component(cube_movement);
    cube->model()->translate({ .5f, .0f, .0f });

    sphere->awake();
    laf::input_manager::toggle_cursor(false);
    
    // main loop
    while(!window->is_open()) {
        window->update();
        window->wait_for_exit();

        laf::input_manager::poll_input();

        // TODO: this is for testing only, remove when done
        {
            sphere->update();
            cube->update();

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