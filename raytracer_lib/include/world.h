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
#include <memory>

class Color;
struct Comps;
class World {
public:
    World() {
    };

    World(const World &) = delete;
    World(World &&) = default;
    static World DefaultWorld();

    PointLight light = PointLight(Point(0, 0, 0), Color(0, 0, 0));
    bool hasLight = false;

    void setLight(PointLight light);

    void addObject(std::unique_ptr<Shape> obj);

    std::vector<std::unique_ptr<Shape>> objects;

    std::vector<Intersection> intersect_world(Ray ray);

    Color shade_hit(Comps comps);

    Color color_at(Ray ray);

    bool is_shadowed(Tuple point);
};

#endif //TEENSYTRACER_WORLD_H
