#include <iostream>
#include "component.hpp"
#include "entity.hpp"

namespace laf {
    unsigned int component::count_ = 0;

    component::component():
    id_(count_++) {

    }

    component::~component() {

    }

    void component::attach(const std::shared_ptr<entity>& target) {
        entity_ = target;
    }

    std::shared_ptr<model> component::model() const {
        auto entity = entity_.lock();
        if (entity != nullptr) {
            return entity->model();
        }

        return { nullptr };
    }
}