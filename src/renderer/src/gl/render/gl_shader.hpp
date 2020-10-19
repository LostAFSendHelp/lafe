#pragma once
#include <GL/glew.h>
#include <string>

namespace laf {
    class gl_shader {
    public:
        const GLenum type_;
        const GLuint id_;

        gl_shader(GLenum type, const char* path);
        ~gl_shader();

        void dispose();
        bool compile() const;
        const std::string& source() const;
    
    private:
        std::string source_;
        const char* get_log() const;
    };
};