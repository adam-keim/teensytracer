//
// Created by Adam Keim on 7/3/20.
//

#ifndef TEENSYTRACER_SHAPES_H
#define TEENSYTRACER_SHAPES_H

#include "tuple.h"
#include "ray.h"
#include "material.h"
#include <vector>
#include <math.h>
#include <Eigen/Dense>

class Shape {
public:
    Shape() {
        transform = Eigen::Matrix4f::Identity();
        material = Material();
    };
    Eigen::Matrix4f transform;
    Material material;

    std::vector<Intersection> intersect(Ray &ray);

    Tuple normal_at(const Tuple& w_p);
    void set_transform(const Eigen::Matrix4f &t) {
        this->transform *= t;
    }

    void set_material(Material material) {
        this->material = material;
    }

    virtual std::vector<Intersection> local_intersect(Ray &ray) {
        return std::vector<Intersection>();
    };

    virtual Tuple local_normal_at(const Tuple &w_p) {
        return Tuple(0, 0, 0, 0);
    };

    friend bool operator==(Shape const &c1, Shape const &c2) {
        return (c1.material == c2.material and c1.transform == c2.transform);
    };
};


class TestShape : public Shape {
public:
    TestShape() : Shape() {};
    Ray saved_ray = Ray(Point(0, 0, 0), Vector(0, 0, 0));

    std::vector<Intersection> local_intersect(Ray &ray) override {
        this->saved_ray = ray;
        return std::vector<Intersection>();
    };

    Tuple local_normal_at(const Tuple &w_p) override;

};


class Sphere : public Shape {
public:
    Sphere() : Shape() {
        origin = Point(0, 0, 0);
        radius = 1;
    };

    std::vector<Intersection> local_intersect(Ray &ray) override;



    Tuple local_normal_at(const Tuple &w_p) override;

private:
    Tuple origin;
    float radius;
};


class Plane : public Shape {
public:
    Plane() : Shape() {

    };

    std::vector<Intersection> local_intersect(Ray &ray) override;

    Tuple local_normal_at(const Tuple& w_p) override;
};

#endif //TEENSYTRACER_SHAPES_H
