//
// Created by Adam Keim on 7/3/20.
//

#ifndef TEENSYTRACER_SHAPES_H
#define TEENSYTRACER_SHAPES_H
#include "tuple.h"
#include "ray.h"
#include <vector>

class Sphere {
public:
    Sphere() {
        origin = Point(0,0,0);
        radius = 1;
    };
    std::vector<float> intersect(Ray ray);
private:
    Tuple origin;
    float radius;
};

#endif //TEENSYTRACER_SHAPES_H
