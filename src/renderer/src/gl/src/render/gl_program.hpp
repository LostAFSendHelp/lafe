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
        void delete_shaders();
        void use() const;
        void dispose();
        bool link();

        template<typename T>
        void set_uniform(const std::string& name, const T& data);

    private:
        std::vector<gl_shader> shaders_;
        std::unordered_map<std::string, GLint> uniforms_;
        const char* get_log() const;
    };

    template<typename T>
    void gl_program::set_uniform(const std::string& name, const T& data) {
        return;
    }

    template<>
    void gl_program::set_uniform<glm::mat4>(const std::string& name, const glm::mat4& data);

    template<>
    void gl_program::set_uniform<glm::vec4>(const std::string& name, const glm::vec4& data);

    template<>
    void gl_program::set_uniform<glm::vec3>(const std::string& name, const glm::vec3& data);

    template<>
    void gl_program::set_uniform<float>(const std::string& name,const float& data);
};