#pragma once
#include <memory>
#include <glm/glm.hpp>
#include "camera.hpp"
#include "mesh.hpp"

namespace laf {
    class renderer {
    public:
        glm::vec3 light_color_;
        
        virtual ~renderer();

        virtual void render(camera* camera) = 0;
        virtual std::shared_ptr<mesh> gen_mesh(const std::vector<vertex>& vertices, const std::vector<unsigned int>& indices) = 0;
        virtual void remove_mesh(unsigned int id) = 0;

    private:

    protected:
        renderer();
    };
};