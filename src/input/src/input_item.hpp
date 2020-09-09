#pragma once

namespace laf {
    struct input_item {
        int positive_;
        int negative_;
        int direction_;

        void test_input() const;
        void accept(int pos, int neg);
    };
};