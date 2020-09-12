#pragma once
#include "../../../model.hpp"
#include "gl_vao.hpp"

namespace laf {
    class gl_model : public model {
    public:
        gl_model(const std::vector<vertex>& vertices, const std::vector<unsigned int>& indices);
        ~gl_model();

        inline const gl_vao& vao() const { return vao_; }

    private:
        gl_vao vao_;
    };
};