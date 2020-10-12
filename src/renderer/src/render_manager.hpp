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
        static void remove_mesh(uint32_t id);
        static void make_camera_current(const std::shared_ptr<camera>& camera);
        static void light_color(const glm::vec3& color);
        static void ambient(float strength);

        static glm::vec3 light_color();
        float ambient();

        static std::shared_ptr<mesh> gen_mesh(const std::vector<vertex>& vertices);

    private:
        static std::unique_ptr<renderer> renderer_;
        static std::shared_ptr<camera> camera_;
    };

    template<>
    void render_manager::init<gl_renderer>();
};