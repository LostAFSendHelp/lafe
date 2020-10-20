#pragma once
#include <vector>
#include <memory>
#include <mesh.hpp>
#include "component.hpp"

namespace laf {
    class entity final {
    public:
        const uint32_t id_;



        /**
         * @brief Constructs a new entity object. This is a mere container for components.
         */
        entity();



        /**
         * @brief Destroys the entity object.
         */
        ~entity();

        
        
        /**
         * @brief Attaches a component to the current entity. Detaches it from its owning entity, if any.
         * 
         * @param target The component to be attached. 
         * @return true if attachment is successful.
         * @return false otherwise.
         */
        bool attach_component(const std::shared_ptr<component>& target);



        /**
         * @brief Removes a child component with the same id as that of the target, if any.
         * 
         * @param target The component to be removed by id.
         * @return true if removal is successful.
         * @return false otherwise.
         */
        bool detach_component(const std::shared_ptr<component>& target);



        /**
         * @brief Removes a child component by id, if any.
         * 
         * @param id The id of the component that is to be removed.
         * @return true if removal is successful.
         * @return false otherwise.
         */
        bool detach_component(uint32_t id);



        /**
         * @brief Removes all child components
         */
        void flush_components();



        /**
         * @brief Gets the component object of the specified type.
         * 
         * @tparam T The component type to be retrieved, must be component-derived.
         * @return std::shared_ptr<T> 
         */
        template<typename T>
        std::shared_ptr<T> get_component() const;



        /**
         * @brief Calls awake() of all child components.
         */
        void awake();



        /**
         * @brief Calls update() of all child components.
         */
        void update();



        /**
         * @brief Adds a mesh to the current entity.
         * 
         * @param mesh The mesh to be added.
         */
        void add_mesh(const std::shared_ptr<mesh>& mesh);



        /**
         * @brief Gets the mesh of the current entity, if any.
         * 
         * @return std::shared_ptr<mesh> 
         */
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