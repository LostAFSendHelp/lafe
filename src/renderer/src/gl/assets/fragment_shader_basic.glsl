#version 330 core

in vec3 v_color;
in vec3 v_normal;
in vec3 v_fragment_position;
out vec4 f_color;

uniform vec3 u_ambient_color = vec3(1.0f);

void main() {
    vec3 f_light_source_position = vec3(40.0f, 20.0f, -30.0f);
    vec3 f_normal = normalize(v_normal);
    vec3 f_direction = normalize(f_light_source_position - v_fragment_position);
    float f_diffuse = max(dot(f_normal, f_direction), .0f);
    f_color = vec4(abs(v_color), 1.0f) * (u_ambient_color + f_diffuse);
}