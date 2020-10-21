#version 330 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;

uniform mat4 u_model;
uniform mat4 u_projection;
uniform mat4 u_view;
uniform vec4 u_light_source_position = vec4(.0f, .0f, .0f, 1.0f);

out vec3 v_normal;
out vec3 v_fragment_position;
out vec3 v_light_source_position;

void main() {
    // position
    vec4 v_position = u_model * vec4(in_position, 1.0f);
    gl_Position = u_projection * u_view * v_position;

    // vectors in view space
    v_fragment_position = vec3(u_view * v_position);
    v_normal = vec3(u_view * u_model * vec4(in_normal, 0.0f));
    v_light_source_position = vec3(u_view * u_light_source_position);
}
