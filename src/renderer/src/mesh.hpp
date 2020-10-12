#pragma once
#include <vector>
#include <vertex.hpp>

namespace laf {
    class mesh {
    public:
        
        /// Id of the mesh.
        const uint32_t id_;




        /// Currently only means the mesh's color is rendered as-is.
        bool is_light_source_;




        /**
         * @brief Constructs a new mesh object
         * 
         * @param is_indexed Whether the mesh should be index-drawn.
         */
        mesh();



        /**
         * @brief Destroys the mesh object
         */
        virtual ~mesh();



        /**
         * @brief Rotates the mesh, applied before translation, if any
         * 
         * @param radians Rotation angle in radians
         * @param axis The axis to rotate around
         * @param normalized Whether the axis should be normalized before the rotation
         */
        virtual void rotate(float radians, const glm::vec3& axis, bool normalized);



        /**
         * @brief The mesh's translation into world space coordinates.
         * 
         * @param translation The incremental translation to make to the mesh.
         */
        virtual void translate(const glm::vec3& translation);



        /**
         * @brief The current rotation of the mesh. Initialized to 1.0f
         * 
         * @return const glm::mat4& rotation
         */
        inline const glm::mat4& rotation() const { return rotation_; }



        /**
         * @brief The current translation of the mesh. Initialized to 1.0f
         * 
         * @return const glm::mat4& translation
         */
        inline const glm::mat4& translation() const { return translation_; }



        /**
         * @brief The model matrix to represent the mesh in world space
         * 
         * @return glm::mat4 model
         */
        inline glm::mat4 model() const { return translation_ * rotation_; }



        /**
         * @brief number of meshes that have been INITIALIZED
         * 
         * @return uint32_t count
         */
        inline static uint32_t count() { return count_; }

    private:
        static uint32_t count_;
        glm::mat4 rotation_{ 1.0f };
        glm::mat4 translation_{ 1.0f };
    };
};