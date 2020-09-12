#include <iostream>
#include <glm/gtc/type_ptr.hpp>
#include "gl_program.hpp"

namespace laf {
    gl_program::gl_program():
    id_(glCreateProgram()) {

    }

    gl_program::~gl_program() {

    }

    void gl_program::gen_shader(GLenum type, const char* path) {
        gl_shader shader{ type, path };
        glAttachShader(id_, shader.id_);
        shaders_.push_back(shader);
    }

    void gl_program::set_uniform(const std::string& name, const glm::mat4& matrix) {
        auto result = uniforms_.find(name);
        GLint location = -1;
        
        if (result == uniforms_.end()) {
            location = glGetUniformLocation(id_, name.c_str());
            if (location > -1) {
                uniforms_[name] = location;
            }
        } else {
            location = result->second;
        }

        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void gl_program::delete_shaders() {
        for (auto& shader : shaders_) {
            glDetachShader(id_, shader.id_);
            glDeleteShader(shader.id_);
        }

        shaders_.clear();
    }

    void gl_program::use() const {
        glUseProgram(id_);
    }

    void gl_program::dispose() {
        delete_shaders();
        glDeleteProgram(id_);
    }

    bool gl_program::link() {
        for (const auto& shader : shaders_) {
            if (!shader.compile()) return false;
        }

        glLinkProgram(id_);

        if (auto log = get_log()) {
            std::cout << "[PROGRAM LINKAGE ERROR] : " << log << std::endl;
            delete[] log;
            return false;
        }

        // TODO: reason whether to delete shaders
        delete_shaders();
        return true;
    }

    const char* gl_program::get_log() const {
        GLint status;
        glGetProgramiv(id_, GL_LINK_STATUS, &status);

        if (status == GL_FALSE) {
            GLint length;
            glGetProgramiv(id_, GL_INFO_LOG_LENGTH, &length);

            char* log = new char[length];
            glGetProgramInfoLog(id_, sizeof(char) * length, nullptr, log);

            return log;
        }

        return nullptr;
    }
}