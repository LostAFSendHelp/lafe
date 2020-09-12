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
        static void init();

        static void poll_input(window* window);
        static void reset();
        static int get_input(const std::string& name);

    private:
        static std::unique_ptr<input> shared_;
    };

    template<>
    void input_manager::init<gl_input>();
}