#include <iostream>
#include "component.hpp"
#include "entity.hpp"

namespace laf {
    unsigned int component::count_ = 0;

    component::component():
    id_(count_++) {

    }

    component::~component() {
        if (entity_ != nullptr) entity_->detach_component(id_);

        std::cout << "Component ID " << id_ << " destroyed" << std::endl;
    }

    void component::attach(entity* target) {
        if (entity_ != nullptr) {
            entity_->detach_component(id_);
        }
        entity_.reset(target);
    }

    void component::detach() {
        entity_.release();
    }

    std::shared_ptr<model> component::model() const {
        static auto test = (entity_ == nullptr);
        if (test) {
            std::cout << test << std::endl;
            test = false; 
        }
        if (entity_ != nullptr) {
            return entity_->model();
        }

        return { nullptr };
    }
}