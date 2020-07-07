//
// Created by Adam Keim on 7/4/20.
//

#include "catch.hpp"
#include "include/world.h"
#include "include/ray.h"
#include "include/tuple.h"
#include "include/matrix_helper.h"
#include <vector>

TEST_CASE("Basic world operations") {
    SECTION("Creating a world") {
        auto w = World();
        CHECK(w.objects.size() == 0);
        CHECK(w.hasLight == false);

    }SECTION("The default world") {
        auto light = PointLight(Point(-10, 10, -10), Color(1, 1, 1));
        std::unique_ptr<Shape> s1 = std::make_unique<Sphere>();
        s1->material.color = Color(.8, 1.0, 0.6);
        s1->material.diffuse = 0.7;
        s1->material.specular = .2;
        std::unique_ptr<Shape> s2 = std::make_unique<Sphere>();
        s2->set_transform(Scaling(.5, .5, .5));
        World w = World::DefaultWorld();
        CHECK(w.light == light);
//        CHECK(w.objects[0] == s1.get());
//        CHECK(w.objects[1] == s2.get());

    }SECTION("Intersect a world with a ray") {
        World w = World::DefaultWorld();
        Ray r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
        std::vector<Intersection> xs = w.intersect_world(r);
//        CHECK(xs.size() == 4);
//        CHECK(xs[0].t == 4);
//        CHECK(xs[1].t == 4.5);
//        CHECK(xs[2].t == 5.5);
//        CHECK(xs[3].t == 6.0);
    }SECTION("Shading an intersection") {
        auto w = World::DefaultWorld();
        auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
        auto shape = w.objects[0].get();
        auto i = Intersection(4, shape);
        auto comps = i.prepare_computations(r);
        auto c = w.shade_hit(comps);
        CHECK(c.isApprox(Color(0.38066, 0.47583, 0.2855)));
    }SECTION("Shading an intersection from the inside") {
        auto w = World::DefaultWorld();
        w.light = PointLight(Point(0, 0.25, 0), Color(1, 1, 1));
        auto r = Ray(Point(0, 0, 0), Vector(0, 0, 1));
        auto shape = w.objects[1].get();
        auto i = Intersection(0.5, shape);
        auto comps = i.prepare_computations(r);
        auto c = w.shade_hit(comps);
        CHECK(c.isApprox(Color(0.90498, 0.90498, 0.90498)));
    }SECTION("The color when a ray misses") {
        auto w = World::DefaultWorld();
        auto r = Ray(Point(0, 0, -5), Vector(0, 1, 0));
        auto c = w.color_at(r);
        CHECK(c == Color(0, 0, 0));
    }SECTION("The color with an intersection behind the ray") {
        auto w = World::DefaultWorld();
        auto &outer = w.objects.at(0);
        outer->material.ambient = 1;
        auto &inner = w.objects.at(1);
        inner->material.ambient = 1;
        auto r = Ray(Point(0, 0, 0.75), Vector(0, 0, -1));
        auto c = w.color_at(r);
        CHECK(c.isApprox(inner->material.color));
    }
}

TEST_CASE("Testing for shadows") {
    SECTION("There is no shadow when nothing is collinear with point and light") {
        World w = World::DefaultWorld();
        auto p = Point(0, 10, 0);
        CHECK(!w.is_shadowed(p));
    }SECTION("The shadow when an object is between the point and the light") {
        World w = World::DefaultWorld();
        auto p = Point(10, -10, 10);
        CHECK(w.is_shadowed(p));
    }SECTION("There is no shadow when an object is behind the light") {
        World w = World::DefaultWorld();
        auto p = Point(-20, 20, -20);
        CHECK(!w.is_shadowed(p));
    }SECTION("There is no shadow when an object is behind the point") {
        World w = World::DefaultWorld();
        auto p = Point(-2, 2, -2);
        CHECK(!w.is_shadowed(p));
    }SECTION("shade_hit() is given an intersection in shadow") {
        auto w = World();
        w.light = PointLight(Point(0, 0, -10), Color(1, 1, 1));
        std::unique_ptr<Shape> s1 = std::make_unique<Sphere>();
        w.addObject(s1);
        std::unique_ptr<Shape> s2 = std::make_unique<Sphere>();
        s2->set_transform(Translation(0, 0, 10));
        w.addObject(s2);
        auto r = Ray(Point(0, 0, 5), Vector(0, 0, 1));
        auto i = Intersection(4, s2.get());
        auto comps = i.prepare_computations(r);
        auto c = w.shade_hit(comps);
        CHECK(c == Color(0.1, 0.1, 0.1));
    }
}
