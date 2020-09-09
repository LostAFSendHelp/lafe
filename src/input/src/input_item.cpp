#include <iostream>
#include <algorithm>
#include "input_item.hpp"

namespace laf {
    void input_item::test_input() const {
        std::cout << "[" << __func__ << "] called" << std::endl;
    }

    void input_item::accept(int pos, int neg) {
        direction_ = (positive_ == negative_) ? std::max(pos, neg) : pos - neg;
    }
};