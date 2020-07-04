//
// Created by Adam Keim on 7/3/20.
//

#ifndef TEENSYTRACER_SHAPES_H
#define TEENSYTRACER_SHAPES_H
#include "tuple.h"
#include "ray.h"
#include "material.h"
#include <vector>
#include <Eigen/Dense>

class Sphere {
public:
    Sphere() {
        origin = Point(0,0,0);
        radius = 1;
        transform = Eigen::Matrix4f::Identity();
        material = Material();
    };
    Material material;
    std::vector<Intersection> intersect(Ray ray);
    friend bool operator==(Sphere const &, Sphere const &);
    Eigen::Matrix4f transform;
    void set_transform(Eigen::Matrix4f t) {
        this->transform *= t;
    }
    void set_material(Material m) {
        this->material = m;
    }
    Tuple normal_at(Tuple w_p) const;

private:
    Tuple origin;
    float radius;
};

#endif //TEENSYTRACER_SHAPES_H
