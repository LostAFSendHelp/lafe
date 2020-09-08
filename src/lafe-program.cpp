#include <input.hpp>
#include <input_item.hpp>
#include <gl_window.hpp>
#include <memory>

int main() {
    std::unique_ptr<laf::window> window{ new laf::gl_window() };
    window->init();
    while(!window->is_open()) {
        window->update();
        window->wait_for_exit();
    }
    window->terminate();

    return 0;
}