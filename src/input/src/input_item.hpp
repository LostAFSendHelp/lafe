#pragma once

namespace laf {
    struct input_item {
        int positive_;
        int negative_;
        int value_;

        void test_input() const;
    };
};