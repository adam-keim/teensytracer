//
// Created by Adam Keim on 7/3/20.
//

#include "include/ray.h"
#include "include/matrix_helper.h"
#include "shapes.h"
#include "catch.hpp"


TEST_CASE("Intersecting Rays with spheres") {
    SECTION("A ray intersects a sphere at two points") {
        auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
        auto s = Sphere();
        auto xs = s.intersect(r);
        CHECK(xs.size() == 2);
        CHECK(xs[0].t == 4.0);
        CHECK(xs[1].t == 6.0);
    }SECTION("A ray intersects a sphere at a tangent") {
        auto r = Ray(Point(0, 1, -5), Vector(0, 0, 1));
        auto s = Sphere();
        auto xs = s.intersect(r);
        CHECK(xs.size() == 2);
        CHECK(xs[0].t == 5.0);
        CHECK(xs[1].t == 5.0);
    }SECTION("A ray misses a sphere") {
        auto r = Ray(Point(0, 2, -5), Vector(0, 0, 1));
        auto s = Sphere();
        auto xs = s.intersect(r);
        CHECK(xs.size() == 0);

    }SECTION("A ray originates inside a sphere") {
        auto r = Ray(Point(0, 0, 0), Vector(0, 0, 1));
        auto s = Sphere();
        auto xs = s.intersect(r);
        CHECK(xs.size() == 2);
        CHECK(xs[0].t == -1.0);
        CHECK(xs[1].t == 1.0);
    }SECTION("A sphere is behind a ray") {
        auto r = Ray(Point(0, 0, 5), Vector(0, 0, 1));
        auto s = Sphere();
        auto xs = s.intersect(r);
        CHECK(xs.size() == 2);
        CHECK(xs[0].t == -6.0);
        CHECK(xs[1].t == -4.0);
    }SECTION("Intersect sets the object on the intersection") {
        auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
        std::shared_ptr<Shape> s = std::make_shared<Sphere>();
        auto xs = s->intersect(r);
        CHECK(xs.size() == 2);
        CHECK(*xs[0].object == *s);
        CHECK(*xs[1].object == *s);
    }

}

TEST_CASE("Computing the normal on a sphere") {
    SECTION("The normal on a sphere at a point on the x axis") {
        auto s = Sphere();
        auto n = s.normal_at(Point(1, 0, 0));
        CHECK(n.isApprox(Vector(1, 0, 0)));
    }SECTION("The normal on a sphere at a point on the y axis") {
        auto s = Sphere();
        auto n = s.normal_at(Point(0, 1, 0));
        CHECK(n.isApprox(Vector(0, 1, 0)));
    }SECTION("The normal on a sphere at a point on the z axis") {
        auto s = Sphere();
        auto n = s.normal_at(Point(0, 0, 1));
        CHECK(n.isApprox(Vector(0, 0, 1)));
    }SECTION("The normal on a sphere at a nonaxial point") {
        auto s = Sphere();
        auto n = s.normal_at(Point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));
        CHECK(n.isApprox(Vector(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3)));
    }SECTION("The normal is a normalized vector") {
        auto s = Sphere();
        auto n = s.normal_at(Point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));
        CHECK(n.isApprox(n.normalized()));
    }

}

