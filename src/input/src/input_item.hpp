#pragma once

namespace laf {
    struct input_item {
        int positive_;
        int negative_;
        int direction_;
        bool down_;

        void test_input() const;
        void accept(int pos, int neg);
    };
};