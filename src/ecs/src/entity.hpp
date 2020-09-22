#pragma once
#include <vector>
#include <memory>
#include <model.hpp>
#include "component.hpp"

namespace laf {
    class entity final {
    public:
        const unsigned int id_;

        entity();
        ~entity();

        bool add_component(const std::shared_ptr<component>& target);
        bool remove_component(const std::shared_ptr<component>& target);
        bool remove_component(unsigned int id);
        
        template<typename T>
        std::shared_ptr<T> get_component() const;

        void awake();
        void update();
        void add_model(const std::shared_ptr<model>& model);
        
        inline std::shared_ptr<model> model() const {
            return model_;
        }

    private:
        static unsigned int count_;
        std::shared_ptr<laf::model> model_;
        std::vector<std::shared_ptr<component>> components_;
    };

    template<typename T>
    std::shared_ptr<T> entity::get_component() const {
        for (const auto& component : components_) {
            if (auto ptr = std::dynamic_pointer_cast<T>(component)) {
                return ptr;
            }
        }

        return { nullptr };
    }
};