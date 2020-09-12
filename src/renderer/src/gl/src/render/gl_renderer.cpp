#include <algorithm>
#include "gl_renderer.hpp"

namespace laf {
    gl_renderer::gl_renderer():
    renderer(),
    program_() {
        // TODO: change logic
        program_.gen_shader(GL_VERTEX_SHADER, "src/renderer/src/gl/assets/vertex_shader.glsl");
        program_.gen_shader(GL_FRAGMENT_SHADER, "src/renderer/src/gl/assets/fragment_shader.glsl");
        program_.link();
        program_.use();
    }

    gl_renderer::~gl_renderer() {

    }

    void gl_renderer::render() {
        for (const auto& model : models_) {
            const auto& vao = model->vao();
            program_.set_uniform("u_rotation", model->rotation());
            program_.set_uniform("u_translation", model->translation());
            vao.bind();
            glDrawElements(GL_TRIANGLES, vao.index_count(), GL_UNSIGNED_INT, nullptr);
            vao.unbind();
        }
    }

    void gl_renderer::render(camera* camera) {
        program_.set_uniform("u_projection", camera->projection());
        program_.set_uniform("u_view", camera->view());
    }

    void gl_renderer::remove_model(unsigned int id) {
        auto removed = std::remove_if(models_.begin(), models_.end(), [id](const std::shared_ptr<gl_model>& model) {
            return model->id == id;
        });

        models_.erase(removed, models_.end());
    }

    std::shared_ptr<model> gl_renderer::gen_model(const std::vector<vertex>& vertices, const std::vector<unsigned int>& indices) {
        std::shared_ptr<model> model{ new gl_model{ vertices, indices } };
        models_.push_back(std::static_pointer_cast<gl_model>(model));

        return model;
    }
};