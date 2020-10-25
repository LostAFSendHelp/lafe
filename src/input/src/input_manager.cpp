#include "input_manager.hpp"

namespace laf {
    std::unique_ptr<input> input_manager::input_{ nullptr };

    input_manager::~input_manager() {

    }

    template<>
    void input_manager::init<gl_input>(const std::shared_ptr<window>& window) {
        _ASSERT(input_ == nullptr);
        input_.reset(new gl_input{ window});
    }

    void input_manager::poll_input() {
        _ASSERT(input_ != nullptr);
        input_->poll();
    }

    void input_manager::reset() {
        _ASSERT(input_ != nullptr);
        input_->reset();
    }

    void input_manager::toggle_cursor(bool on) {
        _ASSERT(input_ != nullptr);
        input_->toggle_cursor(on);
    }

    int input_manager::get_input(const std::string& name) {
        _ASSERT(input_ != nullptr);
        return input_->get_input(name);
    }

    bool input_manager::get_key_down(const std::string& name) {
        _ASSERT(input_ != nullptr);
        return input_->get_key_down(name);
    }

    std::pair<double, double> input_manager::cursor_location() {
        _ASSERT(input_ != nullptr);
        return input_->cursor_location();
    }

    std::pair<double, double> input_manager::cursor_axes(bool normalized) {
        _ASSERT(input_ != nullptr);
        return input_->cursor_axes(normalized);
    }
}