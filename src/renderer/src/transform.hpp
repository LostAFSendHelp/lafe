#pragma once
#include <glm/glm.hpp>
#include <memory>
#include <vector>

namespace laf {
    class transform final {
    public:
        /// Id of the transform
        const uint32_t id_;

        /**
         * @brief Constructs a new transform object.
         */
        transform();



        /**
         * @brief Destroys the transform object.
         */
        ~transform();
        
        

        /**
         * @brief The current translation of the mesh. Initialized to 1.0f
         * 
         * @return const glm::mat4& translation
         */
        inline const glm::mat4& translation() const { return translation_; }



        /**
         * @brief The current rotation of the mesh. Initialized to 1.0f
         * 
         * @return const glm::mat4& rotation
         */
        inline const glm::mat4& rotation() const { return rotation_; }



        /**
         * @brief The local transformation of the transform
         * 
         * @return glm::mat4 
         */
        inline glm::mat4 transformation() const { return translation_ * rotation_; }



        /**
         * @brief The global transformation of the transform
         * 
         * @return glm::mat4 
         */
        inline glm::mat4 model() const { return transformation() * i_translation_ * i_rotation_; }



        /**
         * @brief Rotates the mesh, applied before translation, if any
         * 
         * @param radians Rotation angle in radians
         * @param axis The axis to rotate around
         * @param normalized Whether the axis should be normalized before the rotation
         * @param finished Whether all necessary transformations have been applied, if TRUE, update all children
         */
        void rotate(float radians, const glm::vec3& axis, bool normalized, bool finished);



        /**
         * @brief The mesh's translation into world space coordinates.
         * 
         * @param translation The incremental translation to make to the mesh.
         * @param finished Whether all necessary transformations have been applied, if TRUE, update all children
         */
        void translate(const glm::vec3& translation, bool finished);



        /**
         * @brief Detachs the transform from its current parent, if any. Retains world coordinates. 
         */
        void detach();




    private:
        static uint32_t count_;

        bool detached_;
        glm::mat4 translation_;
        glm::mat4 rotation_;
        glm::mat4 i_translation_;
        glm::mat4 i_rotation_;
        std::vector<std::weak_ptr<transform>> children_;



        /**
         * @brief Adds a transform as children, meaning all subsequent transformations are applied down the hierarchy.
         * 
         * @param child The child transform to add.
         */
        void attach_child(const std::shared_ptr<transform>& child);



        /**
         * @brief Inherits the current translation of the parent.
         * 
         * @param translation The translation to inherit.
         * @param rotation The rotation to inherit
         */
        void inherit(const glm::mat4& translation, const glm::mat4& rotation);



        /**
         * @brief Applies the current global transformations to all children
         */
        void update_children();
    };
};