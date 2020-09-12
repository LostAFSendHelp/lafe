#pragma once 
#include <vector>
#include <unordered_map>
#include <glm/glm.hpp>
#include "gl_shader.hpp"

namespace laf {
    class gl_program {
    public:
        const GLuint id_;

        gl_program();
        ~gl_program();

        void gen_shader(GLenum type, const char* path);
        void set_uniform(const std::string& name, const glm::mat4& matrix);
        void delete_shaders();
        void use() const;
        void dispose();
        bool link();

    private:
        std::vector<gl_shader> shaders_;
        std::unordered_map<std::string, GLint> uniforms_;
        const char* get_log() const;
    };
};