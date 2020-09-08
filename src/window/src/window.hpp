#pragma once

namespace laf {
    class window {
    public:
        virtual ~window();

        virtual void init() = 0;
        virtual void update() = 0;
        virtual bool is_open() const = 0;
        virtual void wait_for_exit() = 0;
        virtual void terminate() = 0;
        virtual int get_key(int key) const = 0;
    protected:
        window();
    };
};