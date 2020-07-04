//
// Created by Adam Keim on 7/4/20.
//

#ifndef TEENSYTRACER_WORLD_H
#define TEENSYTRACER_WORLD_H

#include "light.h"
#include "shapes.h"
#include "tuple.h"
#include "color.h"
#include <vector>

class World {
public:
    World() {
    };

    static World DefaultWorld();

    PointLight light = PointLight(Point(0, 0, 0), Color(0, 0, 0));
    bool hasLight = false;

    void setLight(PointLight light);

    void addObject(Sphere obj);

    std::vector<Sphere> objects;

    std::vector<Intersection> intersect_world(Ray ray);
};

#endif //TEENSYTRACER_WORLD_H
