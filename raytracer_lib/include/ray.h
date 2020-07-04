//
// Created by Adam Keim on 7/3/20.
//

#ifndef TEENSYTRACER_RAY_H
#define TEENSYTRACER_RAY_H

#include "tuple.h"
#include "Eigen/Dense"
#include <vector>
#include <iostream>

class Sphere;

class Ray {
public:
    Ray(Tuple origin, Tuple direction) : origin(origin), direction(direction) {}

    Tuple origin;
    Tuple direction;


    Tuple position(float t);

    Ray transform(Eigen::Matrix4f t);
};

class Intersection {
public:
    Intersection() {
        isBlank = true;
        t = 0;
        object = nullptr;
    };

    Intersection(float t, Sphere *obj) : t(t) {
        object = obj;
        isBlank = false;
    };

    friend bool operator==(const Intersection &a, const Intersection &b) {
        return a.t == b.t and a.object == b.object;
    }

    float t;
    Sphere *object;
    bool isBlank;
};

Intersection hit(std::vector<Intersection> xs);


#endif //TEENSYTRACER_RAY_H
