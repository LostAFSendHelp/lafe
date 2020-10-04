#version 330 core

in vec3 v_color;
in vec3 v_light_color;

out vec4 f_color;

void main() {
    f_color = vec4(abs(v_color), 1.0f) * vec4(v_light_color, 1.0f);
}