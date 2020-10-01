#ifdef __DEBUG__
    #include <iostream>
#endif

#include "entity.hpp"

namespace laf {
    unsigned int entity::count_ = 0;

    entity::entity():
    id_(0) {
        #ifdef __DEBUG__
            std::cout << "Entity ID " << id_ << " created" << std::endl;
        #endif
    }

    entity::~entity() {
        flush_components();
        #ifdef __DEBUG__
            std::cout << "Entity ID " << id_ << " destroyed" << std::endl;
        #endif
    }

    bool entity::attach_component(const std::shared_ptr<component>& target) {
        // TODO: consider if necessary to check for duplicate
        components_.push_back(target);
        target->attach(this);
        return true;
    }

    bool entity::detach_component(const std::shared_ptr<component>& target) {
        if (!components_.empty()) {
            auto removed = std::remove_if(components_.begin(), components_.end(), [target](const std::shared_ptr<component>& component) {
                auto result = (target->id_ == component->id_);
                if (result) target->detach();
                return result;
            });

            components_.erase(removed, components_.end());
        }

        return true;
    }

    bool entity::detach_component(unsigned int id) {
        if (!components_.empty()) {
            auto removed = std::remove_if(components_.begin(), components_.end(), [id](const std::shared_ptr<component>& target) {
                auto result = target->id_ == id;
                if (result) target->detach();
                return result;
            });

            components_.erase(removed, components_.end());
        }
        
        return true;
    }

    void entity::flush_components() {
        #ifdef __DEBUG__
            if (!components_.empty()) {
                std::cout << "Flushing all components on Entity ID " << id_ << std::endl;
            }
        #endif

        for (auto& component : components_) {
            component->detach();
        }

        components_.clear();
    }

    void entity::awake() {
        for (auto& component : components_) {
            component->awake();
        }
    }

    void entity::update() {
        for (auto& component : components_) {
            component->update();
        }
    }

    void entity::add_model(const std::shared_ptr<laf::model>& model) {
        model_ = model;
    }
}