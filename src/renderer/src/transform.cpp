#ifdef __DEBUG__
    #include <iostream>
#endif

#include <glm/gtc/matrix_transform.hpp>
#include "transform.hpp"

namespace laf {
    uint32_t transform::count_ = 0;

    transform::transform():
    id_(count_++),
    rotation_(1.0f),
    translation_(1.0f),
    i_translation_(1.0f),
    i_rotation_(1.0f),
    detached_(false) {
        #ifdef __DEBUG__
            std::cout << "Transform ID " << id_ << " created" << std::endl;
        #endif
    }

    transform::~transform() {
        #ifdef __DEBUG__
            std::cout << "Transform ID " << id_ << " destroyed" << std::endl;
        #endif
    }

    void transform::rotate(float radians, const glm::vec3& axis, bool normalized, bool finished) {
        rotation_ = glm::rotate(rotation_,
                                radians,
                                normalized ? glm::normalize(axis) : axis);

        if (finished) update_children();
    }

    void transform::translate(const glm::vec3& translation, bool finished) {
        translation_ = glm::translate(translation_, translation);
        if (finished) update_children();
    }

    void transform::attach_child(const std::shared_ptr<transform>& child) {
        children_.push_back(child);
    }

    void transform::detach() {
        translation_ *= i_translation_;
        rotation_ *= i_rotation_;
        i_translation_ = glm::mat4{ 1.0f };
        i_rotation_ = glm::mat4{ 1.0f };

        detached_ = true;
    }

    void transform::update_children() {
        // container for empty pointers
        std::vector<uint32_t> _indices{ };
        uint32_t _index = 0;

        // update
        for (auto& _child : children_) {
            auto _transform = _child.lock();
            if (_transform == nullptr || _transform->detached_) {
                _indices.push_back(_index++);
                if (_transform != nullptr) _transform->detached_ = false;
            } else {
                _transform->inherit(translation_, rotation_);
            }
        }

        // erase empty pointers: switch erased elements to back then pop
        for (const auto& _idx : _indices) {
            children_[_idx] = children_.back();
            children_.pop_back();
        }
    }

    void transform::inherit(const glm::mat4& translation, const glm::mat4& rotation) {
        i_translation_ = translation;
        i_rotation_ = rotation;
        update_children();
    }
}