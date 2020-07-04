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
        auto s = Sphere();
        auto xs = s.intersect(r);
        CHECK(xs.size() == 2);
        CHECK(xs[0].object == &s);
        CHECK(xs[1].object == &s);
    }SECTION("A sphere's default transformation") {
        auto s = Sphere();
        CHECK(s.transform == Eigen::Matrix4f::Identity());
    }SECTION("Changing a sphere's transformation") {
        auto s = Sphere();
        auto t = Translation(2, 3, 4);
        s.set_transform(t);
        CHECK(s.transform == t);
    }

    SECTION("Intersecting a scaled sphere with a ray") {
        auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
        auto s = Sphere();
        s.set_transform(Scaling(2, 2, 2));
        auto xs = s.intersect(r);
        CHECK(xs.size() == 2);
        CHECK(xs[0].t == 3);
        CHECK(xs[1].t == 7);
    }SECTION("Intersecting a translated sphere with a ray") {
        auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
        auto s = Sphere();
        s.set_transform(Translation(5, 0, 0));
        auto xs = s.intersect(r);
        CHECK(xs.size() == 0);
    }

}

TEST_CASE("Computing the normal on a sphere") {
    SECTION("The normal on a sphere at a point on the x axis") {
        auto s = Sphere();
        auto n = s.normal_at(Point(1, 0, 0));
        CHECK(n == Vector(1, 0, 0));
    }SECTION("The normal on a sphere at a point on the y axis") {
        auto s = Sphere();
        auto n = s.normal_at(Point(0, 1, 0));
        CHECK(n == Vector(0, 1, 0));
    }SECTION("The normal on a sphere at a point on the z axis") {
        auto s = Sphere();
        auto n = s.normal_at(Point(0, 0, 1));
        CHECK(n == Vector(0, 0, 1));
    }SECTION("The normal on a sphere at a nonaxial point") {
        auto s = Sphere();
        auto n = s.normal_at(Point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));
        CHECK(n.isApprox(Vector(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3)));
    }SECTION("The normal is a normalized vector") {
        auto s = Sphere();
        auto n = s.normal_at(Point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));
        CHECK(n.isApprox(n.normalized()));
    }SECTION("Computing the normal on a translated sphere") {
        auto s = Sphere();
        s.set_transform(Translation(0, 1, 0));
        auto n = s.normal_at(Point(0, 1.70711, -0.70711));
        CHECK(n.isApprox(Vector(0, 0.70711, -0.70711)));
    }SECTION("Computing the normal on a transformed sphere") {
        auto s = Sphere();
        auto m = Scaling(1, 0.5, 1) * Rotation_Z(M_PI / 5);
        s.set_transform(m);
        auto n = s.normal_at(Point(0, sqrt(2) / 2, -sqrt(2) / 2));
        CHECK(n.isApprox(Vector(0, 0.97014, -0.24254)));
    }
}

TEST_CASE("Sphere Materials") {
    SECTION("A sphere has a default material") {
        auto s = Sphere();
        auto m = s.material;
        CHECK(m == Material());
    }SECTION("A sphere can be assigned a material") {
        auto s = Sphere();
        auto m = Material();
        m.ambient = 1;
        s.set_material(m);
        CHECK(s.material == m);
    }
}