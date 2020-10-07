#version 330 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_color;

uniform mat4 u_model;
uniform mat4 u_projection;
uniform mat4 u_view;
uniform vec3 u_light_color;

out vec3 v_color;

void main() {
    gl_Position = u_projection * u_view * u_model * vec4(in_position, 1.0f);
    v_color = in_color * u_light_color;
}
