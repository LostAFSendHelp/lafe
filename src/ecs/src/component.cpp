#ifdef __DEBUG__
    #include <iostream>
#endif

#include "component.hpp"
#include "entity.hpp"

namespace laf {
    unsigned int component::count_ = 0;

    component::component():
    id_(count_++) {
        #ifdef __DEBUG__
            std::cout << "Component ID " << id_ << " created" << std::endl;
        #endif
    }

    component::~component() {
        if (entity_ != nullptr) entity_->detach_component(id_);
        
        #ifdef __DEBUG__
            std::cout << "Component ID " << id_ << " destroyed" << std::endl;
        #endif
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
        if (entity_ != nullptr) {
            return entity_->model();
        }

        return { nullptr };
    }
}