#include "entity.hpp"

namespace laf {
    unsigned int entity::count_ = 0;

    entity::entity():
    id_(0) {

    }

    entity::~entity() {

    }

    bool entity::add_component(const std::shared_ptr<component>& target) {
        // TODO: consider if necessary to check for duplicate
        components_.push_back(target);
        return true;
    }

    bool entity::remove_component(const std::shared_ptr<component>& target) {
        if (!components_.empty()) {
            auto removed = std::remove_if(components_.begin(), components_.end(), [target](const std::shared_ptr<component>& component) {
                return target->id_ == component->id_;
            });

            components_.erase(removed, components_.end());
        }

        return true;
    }

    bool entity::remove_component(unsigned int id) {
        if (!components_.empty()) {
            auto removed = std::remove_if(components_.begin(), components_.end(), [id](const std::shared_ptr<component>& target) {
                return target->id_ == id;
            });

            components_.erase(removed, components_.end());
        }
        
        return true;
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