//
// Created by Adam Keim on 7/3/20.
//

#include "include/shapes.h"

std::vector<float> Sphere::intersect(Ray ray) {
    auto xs = std::vector<float>();
    auto sphere_to_ray = ray.origin - this->origin;
    auto a = ray.direction.dot(ray.direction);
    auto b = 2 * ray.direction.dot(sphere_to_ray);
    auto c = sphere_to_ray.dot(sphere_to_ray) - 1;
    float discriminant = pow(b, 2) - 4 * a * c;
    if(discriminant < 0) {
        return xs;
    } else {
        float t1 = (-b - sqrt(discriminant)) / (2 * a);
        float t2 = (-b + sqrt(discriminant)) / (2 * a);
        xs.push_back(t1);
        xs.push_back(t2);
        return xs;
    }



}
