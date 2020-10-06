#pragma once
#include "../../../mesh.hpp"
#include "gl_vao.hpp"

namespace laf {
    class gl_mesh : public mesh {
    public:
        gl_mesh(const std::vector<vertex>& vertices, const std::vector<unsigned int>& indices);
        ~gl_mesh();

        inline const gl_vao& vao() const { return vao_; }

    private:
        gl_vao vao_;
    };
};