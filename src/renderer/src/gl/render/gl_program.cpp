#ifdef __DEBUG__
    #include <iostream>
#endif

#include <glm/gtc/type_ptr.hpp>
#include "gl_program.hpp"

namespace laf {
    gl_program::gl_program():
    id_(glCreateProgram()) {
        #ifdef __DEBUG__
            std::cout << "Program ID " << id_ << " created" << std::endl;
        #endif
    }

    gl_program::~gl_program() {

    }

    void gl_program::gen_shader(GLenum type, const char* path) {
        gl_shader _shader{ type, path };
        glAttachShader(id_, _shader.id_);
        shaders_.push_back(_shader);
    }

    void gl_program::delete_shaders() {
        for (auto& _shader : shaders_) {
            glDetachShader(id_, _shader.id_);
            glDeleteShader(_shader.id_);
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
        for (const auto& _shader : shaders_) {
            if (!_shader.compile()) return false;
        }

        glLinkProgram(id_);

        #ifdef __DEBUG__
            if (auto log = get_log()) {
                std::cout << "[PROGRAM LINKAGE ERROR] : " << log << std::endl;
                delete[] log;
                return false;
            }
        #endif

        // TODO: reason whether to delete shaders
        delete_shaders();
        return true;
    }

    const char* gl_program::get_log() const {
        GLint _status;
        glGetProgramiv(id_, GL_LINK_STATUS, &_status);

        if (_status == GL_FALSE) {
            GLint _length;
            glGetProgramiv(id_, GL_INFO_LOG_LENGTH, &_length);

            char* _log = new char[_length];
            glGetProgramInfoLog(id_, sizeof(char) * _length, nullptr, _log);

            return _log;
        }

        return nullptr;
    } 

    template<>
    void gl_program::set_uniform<glm::mat4>(const std::string& name, const glm::mat4& data) {
        auto _result = uniforms_.find(name);
        GLint _location = -1;
        
        if (_result == uniforms_.end()) {
            _location = glGetUniformLocation(id_, name.c_str());
            if (_location > -1) {
                uniforms_[name] = _location;
            } else {
                // TODO: silently abort if no such uniform found, include this in documentation
                return;
            }
        } else {
            _location = _result->second;
        }

        glUniformMatrix4fv(_location, 1, GL_FALSE, glm::value_ptr(data));
    }

    template<>
    void gl_program::set_uniform<glm::vec4>(const std::string& name, const glm::vec4& data) {
        auto _result = uniforms_.find(name);
        GLint _location = -1;
        
        if (_result == uniforms_.end()) {
            _location = glGetUniformLocation(id_, name.c_str());
            if (_location > -1) {
                uniforms_[name] = _location;
            } else {
                // TODO: silently abort if no such uniform found, include this in documentation
                return;
            }
        } else {
            _location = _result->second;
        }

        glUniform4fv(_location, 1, glm::value_ptr(data));
    }

    template<>
    void gl_program::set_uniform<glm::vec3>(const std::string& name, const glm::vec3& data) {
        auto _result = uniforms_.find(name);
        GLint _location = -1;
        
        if (_result == uniforms_.end()) {
            _location = glGetUniformLocation(id_, name.c_str());
            if (_location > -1) {
                uniforms_[name] = _location;
            } else {
                // TODO: silently abort if no such uniform found, include this in documentation
                return;
            }
        } else {
            _location = _result->second;
        }

        glUniform3fv(_location, 1, glm::value_ptr(data));
    }

    template<>
    void gl_program::set_uniform<float>(const std::string& name, const float& data) {
        auto _result = uniforms_.find(name);
        GLint _location = -1;
        
        if (_result == uniforms_.end()) {
            _location = glGetUniformLocation(id_, name.c_str());
            if (_location > -1) {
                uniforms_[name] = _location;
            } else {
                // TODO: silently abort if no such uniform found, include this in documentation
                return;
            }
        } else {
            _location = _result->second;
        }

        glUniform1f(_location, data);
    }
}