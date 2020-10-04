#include <algorithm>
#include "gl_renderer.hpp"

namespace laf {
    gl_renderer::gl_renderer():
    renderer(),
    basic_program_(),
    light_source_program_() {
        // TODO: change logic
        basic_program_.gen_shader(GL_VERTEX_SHADER, "src/renderer/src/gl/assets/vertex_shader.glsl");
        basic_program_.gen_shader(GL_FRAGMENT_SHADER, "src/renderer/src/gl/assets/fragment_shader_basic.glsl");
        basic_program_.link();

        light_source_program_.gen_shader(GL_VERTEX_SHADER, "src/renderer/src/gl/assets/vertex_shader.glsl");
        light_source_program_.gen_shader(GL_FRAGMENT_SHADER, "src/renderer/src/gl/assets/fragment_shader_light_source.glsl");
        light_source_program_.link();
    }

    gl_renderer::~gl_renderer() {

    }

    void gl_renderer::render(camera* camera) {
        for (const auto& _model : models_) {
            const auto& _vao = _model->vao();
            auto& _program = (_model->is_light_source_) ? light_source_program_ : basic_program_;
            _program.use();
            _program.set_uniform("u_rotation", _model->rotation());
            _program.set_uniform("u_translation", _model->translation());
            _program.set_uniform("u_light_color", light_color_);
            _vao.bind();
            glDrawElements(GL_TRIANGLES, _vao.index_count(), GL_UNSIGNED_INT, nullptr);
            _vao.unbind();

            _program.set_uniform("u_projection", camera->projection());
            _program.set_uniform("u_view", camera->view());
        }
    }

    void gl_renderer::remove_model(unsigned int id) {
        auto _removed = std::remove_if(models_.begin(), models_.end(), [id](const std::shared_ptr<gl_model>& model) {
            return model->id_ == id;
        });

        models_.erase(_removed, models_.end());
    }

    std::shared_ptr<model> gl_renderer::gen_model(const std::vector<vertex>& vertices, const std::vector<unsigned int>& indices) {
        std::shared_ptr<model> _model{ new gl_model{ vertices, indices } };
        models_.push_back(std::static_pointer_cast<gl_model>(_model));

        return _model;
    }
};