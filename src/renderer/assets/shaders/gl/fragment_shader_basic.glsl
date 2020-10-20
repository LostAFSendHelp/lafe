#version 330 core

in vec3 v_normal;
in vec3 v_fragment_position;
out vec4 f_color;

uniform vec3 u_light_color = vec3(1.0f);
uniform vec4 u_light_source_position = vec4(.0f, .0f, .0f, 1.0f);
uniform vec3 u_overlay_color = vec3(1.0f);
uniform vec3 u_pov = vec3(1.0f);
uniform float u_ambient = 0.1f;

void main() {
    float f_spec_str = .5f;

    vec3 f_normal = normalize(v_normal);
    vec3 f_direction = normalize(vec3(u_light_source_position) - v_fragment_position);
    vec3 f_diffuse = max(dot(f_normal, f_direction) / 2.0f, .0f) * u_light_color;
    
    vec3 f_view = normalize(u_pov - v_fragment_position);
    vec3 f_reflect_direction = reflect(-f_direction, v_normal);
    float f_specular = pow(max(dot(f_view, f_reflect_direction), .0f), 128);
    vec3 f_spec_color = u_light_color * f_specular * f_spec_str;

    vec3 result = (u_ambient + f_diffuse + f_spec_color) * u_overlay_color;
    f_color = vec4(result, 1.0f);
}