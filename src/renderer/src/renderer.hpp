#pragma once
#include <memory>
#include <glm/glm.hpp>
#include "light_source.hpp"
#include "camera.hpp"
#include "mesh.hpp"

namespace laf {
    class renderer {
    public:
        virtual ~renderer();

        virtual void render(const std::shared_ptr<camera>& camera, const std::shared_ptr<light_source>& light_source) = 0;
        virtual std::shared_ptr<mesh> gen_mesh(const std::vector<vertex>& vertices) = 0;
        virtual void remove_mesh(uint32_t id) = 0;

        friend class render_manager;

    private:

    protected:
        glm::vec3 light_color_;
        float ambient_;

        renderer();
    };
};