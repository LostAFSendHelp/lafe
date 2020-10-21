#version 330 core

in vec3 v_light_color;

out vec4 f_color;

uniform vec3 u_overlay_color = vec3(1.0f);

void main() {
    f_color = vec4(v_light_color * u_overlay_color, 1.0f);
}