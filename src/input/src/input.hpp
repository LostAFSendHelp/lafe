#pragma once
#include "input_item.hpp"
#include "window.hpp"

namespace laf {
    class input {
    public:
        virtual ~input();

        virtual void poll(const std::shared_ptr<window>& window) = 0;
        virtual void reset() = 0;
        virtual void toggle_cursor(const std::shared_ptr<window>& window, bool on) = 0;
        
        virtual int get_input(const std::string& name) const = 0;
        virtual std::pair<double, double> cursor_location() const = 0;
        virtual std::pair<double, double> cursor_axes(bool normalized) const = 0;

    protected:
        input();
    };
};