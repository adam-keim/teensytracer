//
// Created by Adam Keim on 7/3/20.
//

#ifndef TEENSYTRACER_RAY_H
#define TEENSYTRACER_RAY_H

#include "tuple.h"

class Sphere;
class Ray {
public:
    Ray(Tuple origin, Tuple direction) : origin(origin), direction(direction) {}

    Tuple origin;
    Tuple direction;


    Tuple position(float t);
};

class Intersection {
public:
    Intersection(float t, Sphere *obj) : t(t) {
        object = obj;
    };
private:
    float t;
    Sphere *object;
};


#endif //TEENSYTRACER_RAY_H
