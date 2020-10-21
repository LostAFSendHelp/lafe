#version 330 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;

uniform float u_ambient = 0.1f;
uniform mat4 u_model;
uniform mat4 u_projection;
uniform mat4 u_view;
uniform vec3 u_light_color = vec3(1.0f);
uniform vec4 u_light_source_position = vec4(.0f, .0f, .0f, 1.0f);

out vec3 v_light_color;

void main() {
    // position
    vec4 v_position = u_model * vec4(in_position, 1.0f);
    gl_Position = u_projection * u_view * v_position;

    // vectors in view space
    vec3 v_fragment_position = vec3(u_view * v_position);
    vec3 v_normal = normalize(vec3(u_view * u_model * vec4(in_normal, 0.0f)));
    vec3 v_light_source_position = vec3(u_view * u_light_source_position);

    // diffuse
    vec3 v_light_direction = normalize(v_fragment_position - v_light_source_position);
    vec3 v_diffuse = max(dot(v_normal, -v_light_direction) / 2.0f, .0f) * u_light_color;

    // specular
    float v_spec_str = .5f;
    vec3 v_reflection = reflect(v_light_direction, v_normal);
    vec3 v_view_direction = normalize(-v_fragment_position);
    vec3 v_specular = pow(max(dot(v_view_direction, v_reflection), .0f), 128) * v_spec_str * u_light_color;

    v_light_color = u_ambient + v_specular + v_diffuse;
}
