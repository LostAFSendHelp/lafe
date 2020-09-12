#include "input_manager.hpp"

namespace laf {
    std::unique_ptr<input> input_manager::shared_ { nullptr };

    input_manager::~input_manager() {

    }

    template<>
    void input_manager::init<gl_input>() {
        _ASSERT(shared_ == nullptr);
        shared_.reset(new gl_input{ });
    }

    void input_manager::poll_input(window* window) {
        _ASSERT(shared_ != nullptr);
        shared_->poll(window);
    }

    void input_manager::reset() {
        _ASSERT(shared_ != nullptr);
        shared_->reset();
    }

    int input_manager::get_input(const std::string& name) {
        _ASSERT(shared_ != nullptr);
        return shared_->get_input(name);
    }
}