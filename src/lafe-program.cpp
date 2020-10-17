#include <glm/gtx/rotate_vector.hpp>
#include <input_manager.hpp>
#include <render_manager.hpp>
#include <gl_window.hpp>
#include <entity.hpp>
#include <derived/translation.hpp>
#include <derived/rotation.hpp>
#include <derived/spinning.hpp>
#include <geometry.hpp>
#include <memory>
#include <iostream>

int main() {

    // setup
    std::shared_ptr<laf::window> _window{ new laf::gl_window{ } };
    _window->init();
    std::shared_ptr<laf::camera> _camera{ new laf::camera{ } };
    
    laf::input_manager::init<laf::gl_input>(_window);
    laf::render_manager::init<laf::gl_renderer>();
    auto _renderer = laf::render_manager::get_instance();
    _renderer->make_camera_current(_camera);

    auto _cube_1 = std::make_shared<laf::entity>();
    auto _cube_2 = std::make_shared<laf::entity>();

    _cube_1->add_mesh(_renderer->gen_mesh(laf::geometry::gen_sample_cube(.5f)));
    _cube_1->mesh()->overlay_color_ = glm::vec3{ .8f, .1f, .1f };
    _cube_1->mesh()->transform_->translate({ .0f, .0f, .0f }, true);
    _cube_2->add_mesh(_renderer->gen_mesh(laf::geometry::gen_sample_cube(.3f)));
    _cube_2->mesh()->overlay_color_ = glm::vec3{ .1f, .8f, .1f };
    _cube_2->mesh()->transform_->translate({ 2.0f, .2f, .0f }, true);

    _cube_1->mesh()->transform_->attach_child(_cube_2->mesh()->transform_);
    _cube_1->attach_component(std::shared_ptr<laf::component>{ new laf::translation{ } });
    _cube_1->attach_component(std::shared_ptr<laf::component>{ new laf::rotation{ } });
    _cube_2->attach_component(std::shared_ptr<laf::component>{ new laf::spinning{ } });
    laf::input_manager::toggle_cursor(false);
    
    // main loop
    while(!_window->is_open()) {
        _window->update();
        _window->wait_for_exit();

        laf::input_manager::poll_input();

        // TODO: this is for testing only, remove when done
        {
            _cube_1->update();
            _cube_2->update();

            static const float TURN_RATE = .0004f;
            auto _front = _camera->front();
            auto _right = _camera->right();
            auto _cursor_axes = laf::input_manager::cursor_axes(false);
            auto _rotation_x = (float)_cursor_axes.second * TURN_RATE * -1;
            auto _rotation_y = (float)_cursor_axes.first * TURN_RATE * -1;
            _front = glm::rotate(_front, _rotation_x, _right);
            _front = glm::rotateY(_front, _rotation_y);
            _camera->set_front(_front);

            // translate
            static const float SPEED = .01f;
            float _horizontal = laf::input_manager::get_input("horizontal");
            float _vertical = laf::input_manager::get_input("vertical");
            auto _position = _camera->position();
            auto _transformation = _vertical * _camera->front() + _horizontal * _camera->right();
            if (_transformation != glm::vec3{ .0f, .0f, .0f }) {
                _position += SPEED * glm::normalize(_transformation);
                _camera->set_position(_position);
            }

        }

        
        _renderer->render();
    }

    _renderer->terminate();
    _window->terminate();

    return 0;
}