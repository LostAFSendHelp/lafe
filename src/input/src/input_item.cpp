#include <iostream>
#include "input_item.hpp"

namespace laf {
    void input_item::test_input() const {
        std::cout << "[" << __func__ << "] called" << std::endl;
    }
};