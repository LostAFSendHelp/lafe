#include <iostream>
#include <GLFW/glfw3.h>
#include "input_impl.hpp"

namespace laf {
    input_impl::input_impl():
    input() {
        items_.insert({"horizontal", { GLFW_KEY_D, GLFW_KEY_A, 0 } });
        items_.insert({"vertical", { GLFW_KEY_W, GLFW_KEY_S, 0 } });
    }

    input_impl::~input_impl() {

    }

    void input_impl::poll(window* window) {
        for (auto& item : items_) {
            auto pos = window->get_key(item.second.positive_);
            auto neg = window->get_key(item.second.negative_);
            item.second.accept(pos, neg);
        }
    }

    void input_impl::reset() {
        static int z = 0;
        if (z++ == 0) {
            std::cout << "[" << __func__ << "] called in " << __FILE__ << std::endl;
        }
    }

    int input_impl::get_input(const std::string& name) const {
        auto item = items_.find(name);
        if (item == items_.end()) return 0;

        return item->second.direction_;
    }
}