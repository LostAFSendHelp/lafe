#include <input_manager.hpp>
#include <gl_window.hpp>
#include <memory>
#include <iostream>

int main() {
    laf::input_manager::init<laf::gl_input>();
    std::unique_ptr<laf::window> window{ new laf::gl_window{ } };
    window->init();
    while(!window->is_open()) {
        window->update();
        window->wait_for_exit();

        laf::input_manager::poll_input(window.get());
        
        if (laf::input_manager::get_input("horizontal") != 0) {
            static int count = 1;
            std::cout << "horizontal " << count++ << std::endl;
        }

        if (laf::input_manager::get_input("vertical") != 0) {
            static int count = 1;
            std::cout << "vertical " << count++ << std::endl;
        }

        laf::input_manager::reset();
    }
    window->terminate();

    return 0;
}