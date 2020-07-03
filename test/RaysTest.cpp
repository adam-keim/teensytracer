//
// Created by Adam Keim on 7/3/20.
//
#include "catch.hpp"
#include "include/tuple.h"
#include "include/ray.h"

TEST_CASE("Creating Rays") {
    SECTION("Creating and querying a ray") {
        auto origin = Point(1,2,3);
        auto dir = Vector(4,5,6);
        auto ray = Ray(origin, dir);
        CHECK(ray.origin == origin);
        CHECK(ray.direction == dir);
    }
    SECTION("Computing a point from a distance") {
        auto r = Ray(Point(2, 3, 4), Vector(1, 0, 0));
        CHECK(r.position(0) == Point(2, 3, 4));
        CHECK(r.position(1) == Point(3, 3, 4));
        CHECK(r.position(-1) == Point(1, 3, 4));
        CHECK(r.position(2.5) == Point(4.5, 3, 4));
    }
}
TEST_CASE("Intersecting rays with spheres") {

}
