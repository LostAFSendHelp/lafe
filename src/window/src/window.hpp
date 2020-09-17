#pragma once
#include <utility>

namespace laf {
    class window {
    public:
        virtual ~window();

        virtual void init() = 0;
        virtual void update() = 0;
        virtual bool is_open() const = 0;
        virtual void wait_for_exit() = 0;
        virtual void terminate() = 0;
        virtual void toggle_cursor(bool on) = 0;
        
        virtual int get_key(int key) const = 0;
        virtual std::pair<double, double> cursor_location() const = 0;
    protected:
        window();
    };
};