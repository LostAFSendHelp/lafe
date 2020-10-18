#pragma once
#include <vector>
#include <memory>
#include <vertex.hpp>
#include "transform.hpp"

namespace laf {
    class mesh {
    public:
        
        /// @brief Whether the mesh SHOULD be rendered: whether the renderer will actually render the mesh or not also depends on whether the mesh has vertex data
        bool should_render_;
        /// @brief Id of the mesh.
        const uint32_t id_;
        /// @brief Currently only means the mesh's color is rendered as-is.
        bool is_light_source_;
        /// @brief The overlay color on the surface of the mesh.
        glm::vec3 overlay_color_;



        /**
         * @brief Constructs a new mesh object.
         */
        mesh();



        /**
         * @brief Destroys the mesh object.
         */
        virtual ~mesh();



        /**
         * @brief number of meshes that have been INITIALIZED.
         * 
         * @return uint32_t
         */
        inline static uint32_t count() { return count_; }



        /**
         * @brief Returns a pointer to the current transform
         * 
         * @return std::shared_ptr<transform> 
         */
        inline std::shared_ptr<transform> transform() const { return transform_; }



        /**
         * @brief Whether the mesh will be rendered. Note that this does not equal the last value passed to toggle_render(bool). E.g: when the mesh is toggled to be rendered, but has no actual vertex data, it won't be rendered then.
         * 
         * @return TRUE if the mesh will be rendered.
         * @return FALSE otherwise.
         */
        virtual bool is_hidden() const = 0;



    private:
        static uint32_t count_;
        std::shared_ptr<laf::transform> transform_;
    };
};