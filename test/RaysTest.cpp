//
// Created by Adam Keim on 7/3/20.
//
#include "catch.hpp"
#include "include/tuple.h"
#include "include/ray.h"
#include "include/matrix_helper.h"

TEST_CASE("Creating Rays") {
    SECTION("Creating and querying a ray") {
        auto origin = Point(1, 2, 3);
        auto dir = Vector(4, 5, 6);
        auto ray = Ray(origin, dir);
        CHECK(ray.origin == origin);
        CHECK(ray.direction == dir);
    }SECTION("Computing a point from a distance") {
        auto r = Ray(Point(2, 3, 4), Vector(1, 0, 0));
        CHECK(r.position(0) == Point(2, 3, 4));
        CHECK(r.position(1) == Point(3, 3, 4));
        CHECK(r.position(-1) == Point(1, 3, 4));
        CHECK(r.position(2.5) == Point(4.5, 3, 4));
    }
}

TEST_CASE("Ray transformations") {
    SECTION("Translating a ray") {
        auto r = Ray(Point(1, 2, 3), Vector(0, 1, 0));
        auto m = Translation(3, 4, 5);
        auto r2 = r.transform(m);
        CHECK(r2.origin == Point(4, 6, 8));
        CHECK(r2.direction == Vector(0, 1, 0));
    }SECTION("Scaling a ray") {
        auto r = Ray(Point(1, 2, 3), Vector(0, 1, 0));
        auto m = Scaling(2, 3, 4);
        auto r2 = r.transform(m);
        CHECK(r2.origin == Point(2, 6, 12));
        CHECK(r2.direction == Vector(0, 3, 0));
    }
}