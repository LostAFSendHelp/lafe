#pragma once
#include <memory>
#include <model.hpp>

namespace laf {
    class entity;
    class component {
    public:
        const unsigned int id_;

        virtual ~component();

        /**
         * @brief Attaches a component to a target \c entity, takes a raw pointer of the target and construct a \c unique_ptr<entity>. That means multiple components of the same \c entity do not share ownership of the \c entity, and thus none of them should directly control the entity's lifetime.
         * 
         * A \c component can only be attached to ONE \c entity (LAF-ECS is still experimental and mostly used for testing). Attaching an owned \c component to a new \c entity will first call \c detach on the \c component itself.
         * 
         * @param target Pointer to the target entity
         */
        void attach(entity* target);



        /** @brief Detaches a component from its current \c entity: releases the \c unique_ptr<entity> to the entity.
         */
        void detach();



        /**
         * @brief Called once before gameloop starts (will be moved to after construction)
         */
        virtual void awake() = 0;



        /**
         * @brief Called every frame during gameloop
         */
        virtual void update() = 0;
        



        /**
         * @brief Returns a \c shared_ptr to the first component of type \c <T> in the owning \c entity's component list. Returns \c nullptr if the \c entity is \c nullptr or no component of type \c <T> is found.
         * 
         * @tparam T \c typename of the \c component.
         * @return std::shared_ptr<T>
         */
        template<typename T>
        std::shared_ptr<T> get_component() const;



        /**
         * @brief Returns a \c shared_ptr to the owning \c entity's \c model object. Returns \c nullptr if either the \c entity or its \c model is \c nullptr.
         * 
         * @return std::shared_ptr<model> 
         */
        std::shared_ptr<model> model() const;

    protected:
        component();

    private:
        static unsigned int count_;
        std::unique_ptr<entity> entity_;
    };

    template<typename T>
    std::shared_ptr<T> component::get_component() const {
        if (entity == nullptr) return { nullptr };
        return entity->get_component<T>();
    }
};