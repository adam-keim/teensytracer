//
// Created by Adam Keim on 7/4/20.
//

#ifndef TEENSYTRACER_MATERIAL_H
#define TEENSYTRACER_MATERIAL_H


#include "color.h"
#include "light.h"
#include "tuple.h"

class Material {
public:
    Material(Color color = Color(1, 1, 1), float ambient = .1, float diffuse = .9, float specular = .9,
             float shininess = 200) : color(color),
                                      ambient(ambient), diffuse(diffuse), specular(specular), shininess(shininess) {};

    Color color;
    float ambient;
    float diffuse;
    float specular;
    float shininess;

    friend bool operator==(const Material &m1, const Material &m2);

    Color lighting(PointLight light, Tuple point, Tuple eyev, Tuple normalv, bool in_shadow = false);
};


#endif //TEENSYTRACER_MATERIAL_H
