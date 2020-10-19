#version 330 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;

uniform mat4 u_model;
uniform mat4 u_projection;
uniform mat4 u_view;

out vec3 v_color;
out vec3 v_normal;
out vec3 v_fragment_position;

void main() {
    vec4 v_position = u_model * vec4(in_position, 1.0f);
    gl_Position = u_projection * u_view * v_position;
    v_fragment_position = vec3(v_position);
    v_normal = vec3(u_model * vec4(in_normal, 0.0f));
}
