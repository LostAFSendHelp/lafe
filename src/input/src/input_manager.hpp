#pragma once
#include <memory>
#include <window.hpp>
#include "gl_input.hpp"

namespace laf {
    class input_manager final {
    public:
        input_manager() = delete;
        ~input_manager();
        
        template<typename T>
        static void init(const std::shared_ptr<window>& window);

        static void poll_input();
        static void reset();
        static void toggle_cursor(bool on);
        static int get_input(const std::string& name);
        static bool get_key_down(const std::string& name);
        static std::pair<double, double> cursor_location();
        static std::pair<double, double> cursor_axes(bool normalized);

    private:
        static std::unique_ptr<input> input_;
    };

    template<>
    void input_manager::init<gl_input>(const std::shared_ptr<window>& window);
}