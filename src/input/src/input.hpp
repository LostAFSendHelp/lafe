#pragma once
#include "input_item.hpp"
#include "window.hpp"

namespace laf {
    class input {
    public:
        virtual ~input();

        virtual void poll(window* window) = 0;
        virtual void reset() = 0;
        virtual int get_input(const std::string& name) const = 0;

    protected:
        input();
    };
};