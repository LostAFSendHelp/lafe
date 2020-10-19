#version 330 core

in vec3 v_normal;
in vec3 v_fragment_position;
out vec4 f_color;

uniform vec3 u_light_color = vec3(1.0f);
uniform vec4 u_light_source_position = vec4(.0f, .0f, .0f, 1.0f);
uniform vec3 u_overlay_color = vec3(1.0f);

void main() {
    vec3 f_normal = normalize(v_normal);
    vec3 f_direction = normalize(vec3(u_light_source_position) - v_fragment_position);
    float f_diffuse = max(dot(f_normal, f_direction), .0f);
    f_color = vec4(abs(u_overlay_color), 1.0f) * (u_light_color + f_diffuse);
}