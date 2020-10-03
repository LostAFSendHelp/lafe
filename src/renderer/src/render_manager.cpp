#include "render_manager.hpp"

namespace laf {
    std::unique_ptr<renderer> render_manager::renderer_{ nullptr };
    std::shared_ptr<camera> render_manager::camera_{ nullptr };

    render_manager::~render_manager() {

    }

    template<>
    void render_manager::init<gl_renderer>() {
        _ASSERT(renderer_ == nullptr);
        renderer_ = std::unique_ptr<renderer>{ new gl_renderer() };
    }

    void render_manager::terminate() {
        renderer_= nullptr;
        camera_ = nullptr;

        _ASSERT(true);
    }

    void render_manager::render() {
        _ASSERT(renderer_ != nullptr && camera_ != nullptr);
        renderer_->render(camera_.get());
        renderer_->render();
    }

    void render_manager::remove_model(unsigned int id) {
        _ASSERT(renderer_ != nullptr);
        renderer_->remove_model(id);
    }

    void render_manager::make_camera_current(const std::shared_ptr<camera>& camera) {
        camera_ = camera;
    }

    std::shared_ptr<model> render_manager::gen_sample_cube() {
        std::vector<laf::vertex> vertices {
            {{-.25f, .25f, .25f }, { 0.0f, 0.0f, 1.0f }},     // TLF
            {{ .25f, .25f, .25f }, { 1.0f, 0.0f, 0.0f }},     // TRF
            {{ .25f, -.25f, .25f }, { 1.0f, 1.0f, 0.0f }},     // BRF
            {{-.25f, -.25f, .25f }, { 0.0f, 1.0f, 0.0f }},     // BLF
            
            {{-.25f, .25f, -.25f }, { 0.0f, 0.0f, 1.0f }},    // TLB
            {{ .25f, .25f, -.25f }, { 1.0f, 0.0f, 0.0f }},    // TRB
            {{ .25f, -.25f, -.25f }, { 1.0f, 1.0f, 0.0f }},    // BRB
            {{-.25f, -.25f, -.25f }, { 0.0f, 1.0f, 0.0f }}     // BLB
        };

        std::vector<unsigned int> indices {
            // front
            0, 1, 2,
            2, 3, 0,
            // right
            1, 5, 6,
            6, 2, 1,
            // back
            7, 6, 5,
            5, 4, 7,
            // left
            4, 0, 3,
            3, 7, 4,
            // bottom
            4, 5, 1,
            1, 0, 4,
            // top
            3, 2, 6,
            6, 7, 3
        };

        return gen_model(vertices, indices);
    }

    std::shared_ptr<model> render_manager::gen_model(std::vector<vertex>& vertices, std::vector<unsigned int>& indices) {
        _ASSERT(renderer_ != nullptr);
        return renderer_->gen_model(vertices, indices);
    }
}