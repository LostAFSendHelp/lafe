#include <iostream>
#include <GLFW/glfw3.h>
#include "gl_input.hpp"

namespace laf {
    gl_input::gl_input(const std::shared_ptr<window>& window):
    input(window),
    x_(800.0f / 2.0f),
    y_(600.0f / 2.0f),
    last_x_(x_),
    last_y_(y_) {

        items_.insert({ "horizontal", { GLFW_KEY_D, GLFW_KEY_A, 0 } });
        items_.insert({ "vertical", { GLFW_KEY_W, GLFW_KEY_S, 0 } });

        items_.insert({ "leftright", { GLFW_KEY_RIGHT, GLFW_KEY_LEFT, 0 } });
        items_.insert({ "updown", { GLFW_KEY_UP, GLFW_KEY_DOWN, 0 } });

        items_.insert({ "rotate", { GLFW_KEY_X, GLFW_KEY_Z, 0 } });
        items_.insert({ "cursor", { GLFW_KEY_Q, GLFW_KEY_Q, 0 } });

        window_->key_down_callback([&](int key) {
            for (auto& item : items_) {
                auto& input = item.second;
                if (input.negative_ == key || input.positive_ == key) {
                    input.down_ = true;
                }
            }
        });
    }

    gl_input::~gl_input() {

    }

    void gl_input::poll() {
        for (auto& item : items_) {
            auto pos = window_->get_key(item.second.positive_);
            auto neg = window_->get_key(item.second.negative_);
            item.second.accept(pos, neg);
        }

        if (window_->is_cursor_enabled()) return;
        auto&& location = window_->cursor_location();
        last_x_ = x_;
        last_y_ = y_;
        x_ = location.first;
        y_ = location.second;
    }

    void gl_input::reset() {
        // x_ = last_x_ = 800.0f / 2.0f;
        // y_ = last_y_ = 600.0f / 2.0f;
        for (auto& item : items_) {
            item.second.down_ = false;
        }
    }

    void gl_input::toggle_cursor(bool on) {
        window_->toggle_cursor(on);

        if (!on) {
            auto _location = window_->cursor_location();
            last_x_ = x_ = _location.first;
            last_y_ = y_ = _location.second;
        }
    }

    int gl_input::get_input(const std::string& name) const {
        auto item = items_.find(name);
        if (item == items_.end()) return 0;

        return item->second.direction_;
    }

    bool gl_input::get_key_down(const std::string& name) const {
        auto item = items_.find(name);
        if (item == items_.end()) return false;

        return item->second.down_;
    }

    std::pair<double, double> gl_input::cursor_location() const {
        return { x_, y_ };
    }

    std::pair<double, double> gl_input::cursor_axes(bool normalized) const {
        static bool just_started = true;
        if (just_started) {
            just_started = false;
            return { .0, .0 };
        }

        auto offset_x = x_ - last_x_;
        auto offset_y = y_ - last_y_;
        offset_x = (normalized && offset_x != 0) ? abs(offset_x) / offset_x : offset_x;
        offset_y = (normalized && offset_y != 0) ? abs(offset_y) / offset_y : offset_y;

        return { offset_x, offset_y };
    }
}