#pragma once
#include "input_item.hpp"
#include "window.hpp"

namespace laf {
    class window;

    class input {
    public:
        input();
        virtual ~input();

        virtual void poll(window* const window);
    protected:
    };
};