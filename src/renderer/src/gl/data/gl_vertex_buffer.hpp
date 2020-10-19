#pragma once
#include <GL/glew.h>

namespace laf {
    class gl_vertex_buffer {
    public:
        const GLenum type;
        virtual ~gl_vertex_buffer();
        
        void bind() const;
        void unbind() const;

        virtual void update_data() = 0;

        GLuint id() const;

    private:
        GLuint id_;

    protected:
        gl_vertex_buffer(GLenum type);
    };
};