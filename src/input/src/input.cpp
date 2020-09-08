#include <iostream>
#include "input.hpp"

namespace laf {
    input::input() {

    }

    input::~input() {

    }

    void input::poll(window* const window) {
        std::cout << "[" << __func__ << "] called" << std::endl;
    }
}