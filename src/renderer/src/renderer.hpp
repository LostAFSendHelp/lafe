#pragma once
#include <memory>
#include "camera.hpp"
#include "model.hpp"

namespace laf {
    class renderer {
    public:
        virtual ~renderer();

        virtual void render() = 0;
        virtual void render(camera* camera) = 0;
        virtual std::shared_ptr<model> gen_model(const std::vector<vertex>& vertices, const std::vector<unsigned int>& indices) = 0;
        virtual void remove_model(unsigned int id) = 0;

    private:

    protected:
        renderer();
    };
};