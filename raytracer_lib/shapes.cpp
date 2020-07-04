//
// Created by Adam Keim on 7/3/20.
//

#include "include/shapes.h"


std::vector<Intersection> Sphere::intersect(Ray ray) {
    auto ray2 = ray.transform(this->transform.inverse());
    auto xs = std::vector<Intersection>();
    auto sphere_to_ray = ray2.origin - this->origin;
    auto a = ray2.direction.dot(ray2.direction);
    auto b = 2 * ray2.direction.dot(sphere_to_ray);
    auto c = sphere_to_ray.dot(sphere_to_ray) - 1;
    float discriminant = pow(b, 2) - 4 * a * c;
    if(discriminant < 0) {
        return xs;
    } else {
        float t1 = (-b - sqrt(discriminant)) / (2 * a);
        float t2 = (-b + sqrt(discriminant)) / (2 * a);
        xs.push_back(Intersection(t1, this));
        xs.push_back(Intersection(t2, this));
        return xs;
    }
}

Tuple Sphere::normal_at(Tuple w_p) const{
    auto object_point = this->transform.inverse() * w_p;
    auto object_normal = object_point - this->origin;
    auto world_normal = this->transform.inverse().transpose() * object_normal;
    auto new_world_normal = Vector(world_normal.x(), world_normal.y(), world_normal.z());
    return new_world_normal.normalized();
}
