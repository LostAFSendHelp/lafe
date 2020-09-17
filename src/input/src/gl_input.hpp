#pragma once
#include <unordered_map>
#include "input.hpp"

namespace laf {
    class gl_input: public input {
    public:
        gl_input();
        ~gl_input();

        void poll(const std::shared_ptr<window>& window) override;
        void reset() override;
        void toggle_cursor(const std::shared_ptr<window>& window, bool on) override;

        int get_input(const std::string& name) const override;
        std::pair<double, double> cursor_location() const override;
        std::pair<double, double> cursor_axes(bool normalized) const override;

    private:
        std::unordered_map<std::string, input_item> items_;
        double x_, y_, last_x_, last_y_;
    };
};