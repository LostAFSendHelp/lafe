#include <fstream>
#include <iostream>
#include "gl_shader.hpp"

namespace laf {
    gl_shader::gl_shader(GLenum type, const char* path):
    id_(glCreateShader(type)),
    type_(type),
    source_("") {
        std::fstream reader{ path };
        std::string line{ "" };

        while (std::getline(reader, line)) {
            source_ += line + "\n";
        }
    }

    gl_shader::~gl_shader() {

    }

    void gl_shader::dispose() {
        glDeleteShader(id_);
    }

    bool gl_shader::compile() const {
        const char* source_string = source_.c_str();
        glShaderSource(id_, 1, &source_string, nullptr);
        glCompileShader(id_);

        if (auto log = get_log()) {
            std::cout << "[SHADER COMPILATION ERROR] : " << log << std::endl;
            delete[] log;
            return false;
        }

        return true;
    }

    const std::string& gl_shader::source() const {
        return source_;
    }

    const char* gl_shader::get_log() const {
        GLint result;
        glGetShaderiv(id_, GL_COMPILE_STATUS, &result);

        if (result == GL_FALSE) {
            GLint length;
            glGetShaderiv(id_, GL_INFO_LOG_LENGTH, &length);
            
            char* log = new char[length];
            glGetShaderInfoLog(id_, sizeof(char) * length, nullptr, log);
            
            return log;
        }

        return nullptr;
    }
}