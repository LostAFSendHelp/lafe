#pragma once
#include <vector>
#include <memory>
#include <mesh.hpp>
#include "component.hpp"

namespace laf {
    class entity final {
    public:
        const uint32_t id_;

        entity();
        ~entity();

        bool attach_component(const std::shared_ptr<component>& target);
        bool detach_component(const std::shared_ptr<component>& target);
        bool detach_component(uint32_t id);
        void flush_components();

        template<typename T>
        std::shared_ptr<T> get_component() const;

        void awake();
        void update();
        void add_mesh(const std::shared_ptr<mesh>& mesh);

        inline std::shared_ptr<mesh> mesh() const {
            return mesh_;
        }

    private:
        static uint32_t count_;
        std::shared_ptr<laf::mesh> mesh_;
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