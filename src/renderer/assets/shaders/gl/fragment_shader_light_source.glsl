#version 330 core

out vec4 f_color;

uniform vec3 u_overlay_color = vec3(1.0f);

void main() {
    f_color = vec4(abs(u_overlay_color), 1.0f);
}