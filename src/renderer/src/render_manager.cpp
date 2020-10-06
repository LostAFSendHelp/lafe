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
    }

    void render_manager::remove_mesh(unsigned int id) {
        _ASSERT(renderer_ != nullptr);
        renderer_->remove_mesh(id);
    }

    void render_manager::make_camera_current(const std::shared_ptr<camera>& camera) {
        camera_ = camera;
    }

    void render_manager::light_color(const glm::vec3& color) {
        _ASSERT(renderer_ != nullptr);
        renderer_->light_color_ = color;
    }

    glm::vec3 render_manager::light_color() {
        _ASSERT(renderer_ != nullptr);
        return renderer_->light_color_;
    }

    std::shared_ptr<mesh> render_manager::gen_mesh(const std::vector<vertex>& vertices, const std::vector<unsigned int>& indices) {
        _ASSERT(renderer_ != nullptr);
        return renderer_->gen_mesh(vertices, indices);
    }

    std::shared_ptr<mesh> render_manager::gen_mesh(const std::pair<std::vector<vertex>, std::vector<unsigned int>>& data) {
        _ASSERT(renderer_ != nullptr);
        return renderer_->gen_mesh(data.first, data.second);
    }
}