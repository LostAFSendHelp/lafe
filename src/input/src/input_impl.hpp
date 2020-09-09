#pragma once
#include <unordered_map>
#include "input.hpp"

namespace laf {
    class input_impl: public input {
    public:
        input_impl();
        ~input_impl();

        void poll(window* window) override;
        void reset() override;

        int get_input(const std::string& name) const;

    private:
        std::unordered_map<std::string, input_item> items_;
    };
};