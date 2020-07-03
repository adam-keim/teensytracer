//
// Created by Adam Keim on 7/3/20.
//

#include "include/ray.h"
#include "shapes.h"
#include "catch.hpp"

TEST_CASE("Intersecting Rays with spheres") {
    SECTION("A ray intersects a sphere at two points") {
        auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
        auto s = Sphere();
        auto xs = s.intersect(r);
        CHECK(xs.size() == 2);
        CHECK(xs[0] == 4.0);
        CHECK(xs[1] == 6.0);
    }SECTION("A ray intersects a sphere at a tangent") {
        auto r = Ray(Point(0, 1, -5), Vector(0, 0, 1));
        auto s = Sphere();
        auto xs = s.intersect(r);
        CHECK(xs.size() == 2);
        CHECK(xs[0] == 5.0);
        CHECK(xs[1] == 5.0);
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
        CHECK(xs[0] == -1.0);
        CHECK(xs[1] == 1.0);
    }SECTION("A sphere is behind a ray") {
        auto r = Ray(Point(0, 0, 5), Vector(0, 0, 1));
        auto s = Sphere();
        auto xs = s.intersect(r);
        CHECK(xs.size() == 2);
        CHECK(xs[0] == -6.0);
        CHECK(xs[1] == -4.0);
    }
}
