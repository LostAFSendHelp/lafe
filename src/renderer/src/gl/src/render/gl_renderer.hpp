#pragma once
#include <memory>
#include <vector>
#include "gl_program.hpp"
#include "../data/gl_model.hpp"
#include "../../../renderer.hpp"

namespace laf {
    class gl_renderer : public renderer {
    public:
        gl_renderer();
        ~gl_renderer();

        void render(camera* camera) override;
        void remove_model(unsigned int id) override;
        std::shared_ptr<model> gen_model(const std::vector<vertex>& vertices, const std::vector<unsigned int>& indices) override;
    
    private:
        // currently using hard coded programs
        gl_program basic_program_;
        gl_program light_source_program_;
        std::vector<std::shared_ptr<gl_model>> models_;
    };
};