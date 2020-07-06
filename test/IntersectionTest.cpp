//
// Created by Adam Keim on 7/3/20.
//

#include "catch.hpp"
#include "include/ray.h"
#include "include/shapes.h"
#include <vector>
#include <iostream>

TEST_CASE("Tracking Intersections") {
    SECTION("An intersection encapsulates t and an object") {
        auto s = Sphere();
        auto i = Intersection(3.5, &s);
        CHECK(i.t == 3.5);
        CHECK(i.object == &s);
    }SECTION("Aggregating Intersections") {
        auto s = Sphere();
        auto i1 = Intersection(1, &s);
        auto i2 = Intersection(2, &s);
        std::vector<Intersection> xs{i1, i2};
        CHECK(xs.size() == 2);
        CHECK(xs[0].t == 1);
        CHECK(xs[1].t == 2);
    }

}

TEST_CASE("Finding the hit") {
    SECTION("The hit, when all intersections have positive t") {
        auto s = Sphere();
        auto i1 = Intersection(1, &s);
        auto i2 = Intersection(2, &s);
        std::vector<Intersection> xs{i2, i1};
        auto i = hit(xs);
        CHECK(i == i1);
    }SECTION("The hit, when some intersections have negative t") {
        auto s = Sphere();
        auto i1 = Intersection(-1, &s);
        auto i2 = Intersection(2, &s);
        std::vector<Intersection> xs{i2, i1};
        auto i = hit(xs);
        CHECK(i == i2);
    }

    SECTION("The hit, when all intersections have negative t") {
        auto s = Sphere();
        auto i1 = Intersection(-2, &s);
        auto i2 = Intersection(-1, &s);
        std::vector<Intersection> xs{i2, i1};
        auto i = hit(xs);
        CHECK(i.isBlank);
    }SECTION("The hit is always the lowest nonnegative intersection") {
        auto s = Sphere();
        auto i1 = Intersection(5, &s);
        auto i2 = Intersection(7, &s);
        auto i3 = Intersection(-3, &s);
        auto i4 = Intersection(2, &s);
        std::vector<Intersection> xs{i1, i2, i3, i4};
        auto i = hit(xs);
        CHECK(i == i4);
    }
}

TEST_CASE("Preparing computations") {
    SECTION("Precomputing the state of an intersection") {
        auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
        Sphere shape = Sphere();
        auto i = Intersection(4, &shape);
        Comps comps = i.prepare_computations(r);
        CHECK(comps.t == i.t);
        CHECK(comps.object == i.object);
        CHECK(comps.point == Point(0, 0, -1));
        CHECK(comps.eyev == Vector(0, 0, -1));
        CHECK(comps.normalv == Vector(0, 0, -1));
    }SECTION("The hit, when an intersection occurs on the outside") {
        auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
        auto shape = Sphere();
        auto i = Intersection(4, &shape);
        Comps comps = i.prepare_computations(r);
        CHECK(comps.inside == false);
    }SECTION("The hit, when an intersection occurs on the inside") {
        auto r = Ray(Point(0, 0, 0), Vector(0, 0, 1));
        auto shape = Sphere();
        auto i = Intersection(1, &shape);
        Comps comps = i.prepare_computations(r);
        CHECK(comps.point == Point(0, 0, 1));
        CHECK(comps.eyev == Vector(0, 0, -1));
        CHECK(comps.inside == true);
        CHECK(comps.normalv == Vector(0, 0, -1));
    }
}
