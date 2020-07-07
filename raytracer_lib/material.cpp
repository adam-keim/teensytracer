//
// Created by Adam Keim on 7/4/20.
//

#include "include/material.h"

bool operator==(const Material &m1, const Material &m2) {
    return (m1.color == m2.color and m1.ambient == m2.ambient and m1.diffuse == m2.diffuse and
            m1.specular == m2.specular and m1.shininess == m2.shininess);
}

Color Material::lighting(PointLight light, Tuple point, Tuple eyev, Tuple normalv, bool in_shadow) {
    Color effective_color = this->color * light.intensity;
    Tuple lightv = (light.position - point).normalized();

    Color c_ambient = effective_color * this->ambient;
    Color c_diffuse = Color(0, 0, 0);
    Color c_specular = Color(0, 0, 0);

    float light_dot_normal = lightv.dot(normalv);
    if (light_dot_normal >= 0 and !in_shadow) {
        c_diffuse = effective_color * this->diffuse * light_dot_normal;
        Tuple neg_light_v = -lightv;
        Tuple reflectv = neg_light_v.reflect(normalv);
        float reflect_dot_eye = reflectv.dot(eyev);
        if (reflect_dot_eye <= 0) {
            c_specular = Color(0, 0, 0);
        } else {
            float factor = pow(reflect_dot_eye, this->shininess);
            c_specular = light.intensity * this->specular * factor;
        }
    }
    return c_ambient + c_diffuse + c_specular;

}
