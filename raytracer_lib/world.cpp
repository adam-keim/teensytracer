//
// Created by Adam Keim on 7/4/20.
//

#include "include/world.h"
#include "include/matrix_helper.h"

World World::DefaultWorld() {
    World w = World();
    PointLight light = PointLight(Point(-10, 10, -10), Color(1,1,1));
    w.setLight(light);

    Sphere s1 = Sphere();
    s1.material.color = Color(.8, 1.0, 0.6);
    s1.material.diffuse = 0.7;
    s1.material.specular = .2;
    w.addObject(s1);

    Sphere s2 = Sphere();
    s2.set_transform(Scaling(.5,.5,.5));
    w.addObject(s2);

    return w;
}

void World::setLight(PointLight light) {
    this->hasLight = true;
    this->light = light;
}

void World::addObject(Sphere obj) {
    this->objects.push_back(obj);
}
