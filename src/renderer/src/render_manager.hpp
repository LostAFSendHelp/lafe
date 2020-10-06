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
        static void remove_mesh(unsigned int id);
        static void make_camera_current(const std::shared_ptr<camera>& camera);
        static void light_color(const glm::vec3& color);

        static glm::vec3 light_color();

        static std::shared_ptr<mesh> gen_mesh(const std::vector<vertex>& vertices, const std::vector<unsigned int>& indices);
        static std::shared_ptr<mesh> gen_mesh(const std::pair<std::vector<vertex>, std::vector<unsigned int>>& data);

    private:
        static std::unique_ptr<renderer> renderer_;
        static std::shared_ptr<camera> camera_;
    };

    template<>
    void render_manager::init<gl_renderer>();
};