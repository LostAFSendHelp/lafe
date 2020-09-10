#pragma once
#include <memory>
#include <window.hpp>
#include "gl_input.hpp"

namespace laf {
    class input_manager final {
    public:
        template<class T>
        static void init();

        static void poll_input(window* window);
        static void reset();
        static int get_input(const std::string& name);

    private:
        static std::shared_ptr<input> shared_;
        
        input_manager();
        ~input_manager();
    };

    template<>
    void input_manager::init<gl_input>();
}