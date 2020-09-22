#pragma once
#include <memory>
#include <model.hpp>

namespace laf {
    class entity;
    class component {
    public:
        const unsigned int id_;

        virtual ~component();

        void attach(const std::shared_ptr<entity>& target);
        virtual void awake() = 0;
        virtual void update() = 0;
        
        template<typename T>
        std::shared_ptr<T> get_component() const;
        std::shared_ptr<model> model() const;

    protected:
        component();

    private:
        static unsigned int count_;
        std::weak_ptr<entity> entity_;
    };

    template<typename T>
    std::shared_ptr<T> component::get_component() const {
        auto entity = entity_.lock();
        if (entity == nullptr) return { nullptr };
        return entity->get_component<T>();
    }
};