#version 330 core

in vec3 v_color;
out vec4 f_color;

uniform float u_ambient = 1.0f;

void main() {
    f_color = vec4(abs(v_color), 1.0f) * u_ambient;
}

// TODO: consider/check if possible to move ambient multiplication to cpu (light_color * ambient)