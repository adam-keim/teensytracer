//
// Created by Adam Keim on 7/5/20.
//

#include "catch.hpp"
#include "include/shapes.h"
#include "include/matrix_helper.h"


TEST_CASE("Basic Test Shape") {
    SECTION("The default transformation") {
        TestShape s = TestShape();
        CHECK(s.transform == Eigen::Matrix4f::Identity());
    }SECTION("Assigning a transformation") {
        TestShape s = TestShape();
        s.set_transform(Translation(2, 3, 4));
        CHECK(s.transform == Translation(2, 3, 4));
    }
}

TEST_CASE("Spheres are Shapes") {
    bool is_base = std::is_base_of<Shape, Sphere>::value;
    CHECK(is_base);
}

TEST_CASE("Test Shape Materials") {
    SECTION("A shape has a default material") {
        auto s = TestShape();
        auto m = s.material;
        CHECK(m == Material());
    }SECTION("A shape can be assigned a material") {
        auto s = TestShape();
        auto m = Material();
        m.ambient = 1;
        s.set_material(m);
        CHECK(s.material == m);
    }
}

TEST_CASE("Intersections with Shapes") {
    SECTION("Intersecting a scaled sphere with a ray") {
        auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
        auto s = TestShape();
        s.set_transform(Scaling(2, 2, 2));
        auto xs = s.intersect(r);
        CHECK(s.saved_ray.origin == Point(0, 0, -2.5));
        CHECK(s.saved_ray.direction == Vector(0, 0, 0.5));
    }SECTION("Intersecting a translated sphere with a ray") {
        auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
        auto s = TestShape();
        s.set_transform(Translation(5, 0, 0));
        auto xs = s.intersect(r);
        CHECK(s.saved_ray.origin == Point(-5, 0, -5));
        CHECK(s.saved_ray.direction == Vector(0, 0, 1));
    }

}

TEST_CASE("Normal Shape tests") {
    SECTION("Computing the normal on a translated shape") {
        auto s = TestShape();
        s.set_transform(Translation(0, 1, 0));
        auto n = s.normal_at(Point(0, 1.70711, -0.70711));
        CHECK(n.isApprox(Vector(0, 0.70711, -0.70711)));
    }
    SECTION("Computing the normal on a transformed shape") {
        auto s = TestShape();
        auto m = Scaling(1, 0.5, 1) * Rotation_Z(M_PI / 5);
        s.set_transform(m);
        auto n = s.normal_at(Point(0, sqrt(2) / 2, -sqrt(2) / 2));
        CHECK(n.isApprox(Vector(0, 0.97014, -0.24254)));
    }
}