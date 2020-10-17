#ifdef __DEBUG__
    #include <iostream>
#endif

#include "render_manager.hpp"

namespace laf {
    std::shared_ptr<render_manager> render_manager::main_{ nullptr };

    render_manager::render_manager():
    renderer_(),
    camera_(),
    light_source_() {

    }

    render_manager::~render_manager() {

    }

    std::shared_ptr<render_manager> render_manager::get_instance() {
        _ASSERT(main_ != nullptr);
        return main_;
    }

    template<>
    void render_manager::init<gl_renderer>() {
        if (main_ != nullptr) return;
        main_ = std::make_shared<render_manager>();
        main_->renderer_ = std::unique_ptr<renderer>{ new gl_renderer() };
        main_->light_source_ = std::make_shared<light_source>();

        #ifdef __DEBUG__
            std::cout << "RENDERER INITIALZIED" << std::endl;
        #endif
    }

    void render_manager::terminate() {
        _ASSERT(main_ != nullptr);
        main_->renderer_ = nullptr;
        main_->camera_ = nullptr;
        main_->light_source_ = nullptr;

        #ifdef __DEBUG__
            std::cout << "RENDERER TERMINATED" << std::endl;
        #endif
    }

    void render_manager::render() {
        _ASSERT(renderer_ != nullptr && camera_ != nullptr && light_source_ != nullptr);
        renderer_->render(camera_, light_source_);
    }

    void render_manager::remove_mesh(uint32_t id) {
        _ASSERT(renderer_ != nullptr);
        renderer_->remove_mesh(id);
    }

    void render_manager::make_camera_current(const std::shared_ptr<camera>& camera) {
        camera_ = camera;
    }

    void render_manager::make_light_source_current(const std::shared_ptr<light_source>& source) {
        light_source_ = source;
    }

    glm::vec3 render_manager::light_color() {
        _ASSERT(renderer_ != nullptr);
        return renderer_->light_color_;
    }

    float render_manager::ambient() {
        _ASSERT(renderer_ != nullptr);
        return renderer_->ambient_;
    }

    std::shared_ptr<mesh> render_manager::gen_mesh(const std::vector<vertex>& vertices) {
        _ASSERT(renderer_ != nullptr);
        return renderer_->gen_mesh(vertices);
    }
}