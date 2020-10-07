#pragma once
#include <memory>
#include <glm/glm.hpp>
#include "camera.hpp"
#include "mesh.hpp"

namespace laf {
    class renderer {
    public:
        virtual ~renderer();

        virtual void render(camera* camera) = 0;
        virtual std::shared_ptr<mesh> gen_mesh(const std::vector<vertex>& vertices, const std::vector<uint32_t>& indices) = 0;
        virtual void remove_mesh(uint32_t id) = 0;

        friend class render_manager;

    private:

    protected:
        glm::vec3 light_color_;
        float ambient_;

        renderer();
    };
};