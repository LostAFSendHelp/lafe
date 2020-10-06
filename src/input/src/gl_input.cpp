#include <iostream>
#include <GLFW/glfw3.h>
#include "gl_input.hpp"

namespace laf {
    gl_input::gl_input(): // TODO: rework initial cursor position
    input(),
    x_(800.0f / 2.0f),
    y_(600.0f / 2.0f),
    last_x_(x_),
    last_y_(y_) {

        items_.insert({ "horizontal", { GLFW_KEY_D, GLFW_KEY_A, 0 } });
        items_.insert({ "vertical", { GLFW_KEY_W, GLFW_KEY_S, 0 } });

        items_.insert({ "leftright", { GLFW_KEY_RIGHT, GLFW_KEY_LEFT, 0 } });
        items_.insert({ "updown", { GLFW_KEY_UP, GLFW_KEY_DOWN, 0 } });

        items_.insert({ "rotate", { GLFW_KEY_X, GLFW_KEY_Z, 0 } });
    }

    gl_input::~gl_input() {

    }

    void gl_input::poll(const std::shared_ptr<window>& window) {
        for (auto& item : items_) {
            auto pos = window->get_key(item.second.positive_);
            auto neg = window->get_key(item.second.negative_);
            item.second.accept(pos, neg);
        }

        auto&& location = window->cursor_location();
        last_x_ = x_;
        last_y_ = y_;
        x_ = location.first;
        y_ = location.second;
    }

    void gl_input::reset() {
        x_ = last_x_ = 800.0f / 2.0f;
        y_ = last_y_ = 600.0f / 2.0f;
    }

    void gl_input::toggle_cursor(const std::shared_ptr<window>& window, bool on) {
        window->toggle_cursor(on);
    }

    int gl_input::get_input(const std::string& name) const {
        auto item = items_.find(name);
        if (item == items_.end()) return 0;

        return item->second.direction_;
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