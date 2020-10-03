#pragma once
#include "gl/src/render/gl_renderer.hpp"
#include "camera.hpp"

namespace laf {
    class render_manager final {
    public:
        render_manager() = delete;
        ~render_manager();

        template<typename T>
        static void init();
        static void terminate();
        static void render();
        static void remove_model(unsigned int id);
        static void make_camera_current(const std::shared_ptr<camera>& camera);
        static std::shared_ptr<model> gen_sample_cube();

        static std::shared_ptr<model> gen_model(std::vector<vertex>& vertices, std::vector<unsigned int>& indices);

    private:
        static std::unique_ptr<renderer> renderer_;
        static std::shared_ptr<camera> camera_;
    };

    template<>
    void render_manager::init<gl_renderer>();
};