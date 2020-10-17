#pragma once
#include "gl/src/render/gl_renderer.hpp"
#include "light_source.hpp"
#include "camera.hpp"

namespace laf {
    class render_manager final {
    public:
        render_manager();
        ~render_manager();
        static std::shared_ptr<render_manager> get_instance();

        template<typename T>
        static void init();
        static void terminate();

        void render();
        void remove_mesh(uint32_t id);
        void make_camera_current(const std::shared_ptr<camera>& camera);
        void make_light_source_current(const std::shared_ptr<light_source>& source);        
        glm::vec3 light_color();
        float ambient();
        std::shared_ptr<mesh> gen_mesh(const std::vector<vertex>& vertices);

    private:

        std::unique_ptr<renderer> renderer_;
        std::shared_ptr<camera> camera_;
        std::shared_ptr<light_source> light_source_;

        static std::shared_ptr<render_manager> main_;
    };

    template<>
    void render_manager::init<gl_renderer>();
};