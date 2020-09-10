#include <iostream>
#include <GLFW/glfw3.h>
#include "gl_input.hpp"

namespace laf {
    gl_input::gl_input():
    input() {
        items_.insert({"horizontal", { GLFW_KEY_D, GLFW_KEY_A, 0 } });
        items_.insert({"vertical", { GLFW_KEY_W, GLFW_KEY_S, 0 } });
    }

    gl_input::~gl_input() {

    }

    void gl_input::poll(window* window) {
        for (auto& item : items_) {
            auto pos = window->get_key(item.second.positive_);
            auto neg = window->get_key(item.second.negative_);
            item.second.accept(pos, neg);
        }
    }

    void gl_input::reset() {
        static int z = 0;
        if (z++ == 0) {
            std::cout << "[" << __func__ << "] called in " << __FILE__ << std::endl;
        }
    }

    int gl_input::get_input(const std::string& name) const {
        auto item = items_.find(name);
        if (item == items_.end()) return 0;

        return item->second.direction_;
    }
}