//
// Created by Adam Keim on 7/4/20.
//

#include "include/world.h"
#include "include/matrix_helper.h"


World World::DefaultWorld() {
    World w = World();
    PointLight light = PointLight(Point(-10, 10, -10), Color(1, 1, 1));
    w.setLight(light);

    std::unique_ptr<Shape> s1 = std::make_unique<Sphere>();
    s1->material.color = Color(.8, 1.0, 0.6);
    s1->material.diffuse = 0.7;
    s1->material.specular = .2;
    w.addObject(std::move(s1));

    std::unique_ptr<Shape> s2 = std::make_unique<Sphere>();
    s2->set_transform(Scaling(.5, .5, .5));
    w.addObject(std::move(s2));

    return w;
}

void World::setLight(PointLight light) {
    this->hasLight = true;
    this->light = light;
}

void World::addObject(std::unique_ptr<Shape> obj) {
    this->objects.push_back(std::move(obj));
}

std::vector<Intersection> World::intersect_world(Ray ray) {
    auto xs = std::vector<Intersection>();
    for (std::unique_ptr<Shape> &o : objects) {
        std::vector<Intersection> o_xs = o->intersect(ray);
        xs.insert(xs.end(), o_xs.begin(), o_xs.end());
        o_xs.clear();
    }
    std::sort(xs.begin(), xs.end());
    return xs;
}

Color World::shade_hit(Comps comps) {
    return comps.object->material.lighting(this->light, comps.point, comps.eyev, comps.normalv,
                                           this->is_shadowed(comps.over_point));
}

Color World::color_at(Ray ray) {
    auto xs = this->intersect_world(ray);
    Intersection xs_hit = hit(xs);
    if (xs_hit.isBlank) {
        return Color(0, 0, 0);
    } else {
        Comps comps = xs_hit.prepare_computations(ray);
        Color c = this->shade_hit(comps);
        return c;
    }
}

bool World::is_shadowed(Tuple point) {
    Tuple v = this->light.position - point;
    float distance = v.norm();
    Tuple direction = v.normalized();
    Ray r = Ray(point, direction);
    auto xs = this->intersect_world(r);
    Intersection h = hit(xs);
    return !h.isBlank and h.t < distance;
}
