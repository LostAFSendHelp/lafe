#pragma once
#include "input_item.hpp"
#include "window.hpp"

namespace laf {
    class input {
    public:
        virtual ~input();

        virtual void poll() = 0;
        virtual void reset() = 0;
        virtual void toggle_cursor(bool on) = 0;
        
        virtual int get_input(const std::string& name) const = 0;
        virtual bool get_key_down(const std::string& name) const = 0;
        virtual std::pair<double, double> cursor_location() const = 0;
        virtual std::pair<double, double> cursor_axes(bool normalized) const = 0;

    protected:
        input(const std::shared_ptr<window>& window);
        std::shared_ptr<window> window_;
    };
};