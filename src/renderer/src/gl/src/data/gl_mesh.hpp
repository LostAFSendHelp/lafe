#pragma once
#include "../../../mesh.hpp"
#include "gl_vao.hpp"

namespace laf {
    class gl_mesh : public mesh {
    public:

        /**
         * @brief Constructs a new gl_mesh object, currently only supports non-indexed drawing
         * 
         * @param vertices Vertex data, each vertex consisting of a location vec3 and one corresponding normal vector
         */
        gl_mesh(const std::vector<vertex>& vertices);



        /**
         * @brief Destroys the gl_mesh object
         */
        ~gl_mesh();



        /**
         * @brief Returns the current VAO of the mesh, consisting of an optional array_buffer and an optional index_buffer
         * 
         * @return const gl_vao& 
         */
        inline const gl_vao& vao() const { 
            _ASSERT(vao_.has_value());
            return vao_.value();
        }



        /**
         * @brief Whether the mesh will be rendered. Note that this does not equal the last value passed to toggle_render(bool). E.g: when should_render_ is set to TRUE, but has no actual vertex data, it won't be rendered then.
         * 
         * @return TRUE if the mesh will be rendered.
         * @return FALSE otherwise.
         */
        inline bool is_hidden() const override {
            return !vao_.has_value() || !should_render_;
        }



    private:
        std::optional<gl_vao> vao_;
    };
};