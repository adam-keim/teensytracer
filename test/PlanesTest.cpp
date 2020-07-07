//
// Created by Adam Keim on 7/6/20.
//

#include "catch.hpp"
#include "include/shapes.h"


TEST_CASE("Plane implementation") {
    SECTION("The normal of a plane is constant everywhere") {
        auto p = Plane();
        Tuple n1 = p.local_normal_at(Point(0, 0, 0));
        Tuple n2 = p.local_normal_at(Point(10, 0, -10));
        Tuple n3 = p.local_normal_at(Point(-5, 0, 150));
        CHECK(n1 == Vector(0, 1, 0));
        CHECK(n2 == Vector(0, 1, 0));
        CHECK(n3 == Vector(0, 1, 0));
    }
}
TEST_CASE("Intersecting Rays with planes") {
    SECTION("Intersect with a ray parallel to the plane") {
        auto p = Plane();
        auto r = Ray(Point(0, 10, 0), Vector(0, 0, 1));
        auto xs = p.local_intersect(r);
        CHECK(xs.size() == 0);
    }
    SECTION("Intersect with a coplanar ray") {
        Plane p = Plane();
        auto r = Ray(Point(0, 0, 0), Vector(0, 0, 1));
        auto xs = p.local_intersect(r);
        CHECK(xs.size() == 0);
    }
    SECTION("A Ray intersecting a plane from above") { ;
        std::shared_ptr<Shape> p = std::make_shared<Plane>();
        auto r = Ray(Point(0, 1, 0), Vector(0, -1, 0));
        auto xs = p->local_intersect(r);
        CHECK(xs.size() == 1);
        CHECK(xs[0].t == 1);
        CHECK(*xs[0].object == *p);
    }
    SECTION("A Ray intersecting a plane from below") { ;
        std::shared_ptr<Shape> p = std::make_shared<Plane>();
        auto r = Ray(Point(0, -1, 0), Vector(0, 1, 0));
        auto xs = p->local_intersect(r);
        CHECK(xs.size() == 1);
        CHECK(xs[0].t == 1);
        CHECK(*xs[0].object == *p);
    }
}