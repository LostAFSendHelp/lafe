#include <input_impl.hpp>
#include <gl_window.hpp>
#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<laf::window> window{ new laf::gl_window() };
    std::unique_ptr<laf::input> input{ new laf::input_impl() };
    window->init();
    while(!window->is_open()) {
        window->update();
        window->wait_for_exit();

        input->poll(window.get());
        if (input->get_input("horizontal") != 0) {
            static int count = 1;
            std::cout << "horizontal " << count++ << std::endl;
        }
        input->reset();
    }
    window->terminate();

    return 0;
}