//
// Created by Adam Keim on 7/3/20.
//

#include <Eigen/Dense>
#include <Eigen/Geometry>
#include "catch.hpp"
#include "include/tuple.h"
#include "include/matrix_helper.h"
#include "cmath"
#include <iostream>

TEST_CASE("Translation") {
    SECTION("Forward Translation") {
        auto m = Translation(5, -3, 2);
        Tuple p = Point(-3, 4, 5);
        CHECK(m * p == Point(2, 1, 7));
    }SECTION("Inverse Translation") {
        auto m = Translation(5, -3, 2);
        Tuple p = Point(-3, 4, 5);
        auto inv = m.inverse();
        CHECK(inv * p == Point(-8, 7, 3));
    }SECTION("Translation Does not affect Vectors") {
        auto t = Translation(5, -3, 2);
        auto v = Vector(-3, 4, 5);
        CHECK(t * v == v);
    }
}

TEST_CASE("Scaling") {
    SECTION("A scaling matrix applied to a point") {
        auto transform = Scaling(2, 3, 4);
        auto p = Point(-4, 6, 8);
        CHECK(transform * p == Point(-8, 18, 32));
    }SECTION("A scaling matrix applied to a vector") {
        auto transform = Scaling(2, 3, 4);
        auto v = Vector(-4, 6, 8);
        CHECK(transform * v == Vector(-8, 18, 32));
    }SECTION("Multiplying by the inverse of a scaling matrix") {
        auto transform = Scaling(2, 3, 4);
        auto inv = transform.inverse();
        auto v = Vector(-4, 6, 8);
        CHECK(inv * v == Vector(-2, 2, 2));
    }SECTION("Reflection is scaling by a negative value") {
        auto transform = Scaling(-1, 1, 1);
        auto p = Point(2, 3, 4);
        CHECK(transform * p == Point(-2, 3, 4));
    }
}

TEST_CASE("Rotation") {
    SECTION("Rotating a point around the x axis") {
        auto p = Point(0, 1, 0);
        auto half_quarter = Rotation_X(M_PI / 4);
        auto full_quarter = Rotation_X(M_PI / 2);
        CHECK((half_quarter * p).isApprox(Point(0, sqrt(2) / 2, sqrt(2) / 2)));
        CHECK((full_quarter * p).isApprox(Point(0, 0, 1)));
    } SECTION("Rotating a point around the y axis") {
        auto p = Point(0, 0, 1);
        auto half_quarter = Rotation_Y(M_PI / 4);
        auto full_quarter = Rotation_Y(M_PI / 2);
        CHECK((half_quarter * p).isApprox(Point(sqrt(2) / 2, 0, sqrt(2) / 2)));
        CHECK((full_quarter * p).isApprox(Point(1, 0, 0)));
    } SECTION("Rotating a point around the z axis") {
        auto p = Point(0, 1, 0);
        auto half_quarter = Rotation_Z(M_PI / 4);
        auto full_quarter = Rotation_Z(M_PI / 2);
        CHECK((half_quarter * p).isApprox(Point(-sqrt(2) / 2, sqrt(2) / 2, 0)));
        CHECK((full_quarter * p).isApprox(Point(-1, 0, 0)));
    }
}

TEST_CASE("Shearing") {
    SECTION("A shearing transformation moves x in proportion to y") {
        auto transform = Shearing(1, 0, 0, 0, 0, 0);
        auto p = Point(2, 3, 4);
        CHECK((transform * p) == Point(5, 3, 4));
    }SECTION("A shearing transformation moves x in proportion to z") {
        auto transform = Shearing(0, 1, 0, 0, 0, 0);
        auto p = Point(2, 3, 4);
        CHECK((transform * p) == Point(6, 3, 4));
    }SECTION("A shearing transformation moves y in proportion to x") {
        auto transform = Shearing(0, 0, 1, 0, 0, 0);
        auto p = Point(2, 3, 4);
        CHECK((transform * p) == Point(2, 5, 4));
    }SECTION("A shearing transformation moves y in proportion to z") {
        auto transform = Shearing(0, 0, 0, 1, 0, 0);
        auto p = Point(2, 3, 4);
        CHECK((transform * p) == Point(2, 7, 4));
    }SECTION("A shearing transformation moves z in proportion to x") {
        auto transform = Shearing(0, 0, 0, 0, 1, 0);
        auto p = Point(2, 3, 4);
        CHECK((transform * p) == Point(2, 3, 6));
    }SECTION("A shearing transformation moves z in proportion to y") {
        auto transform = Shearing(0, 0, 0, 0, 0, 1);
        auto p = Point(2, 3, 4);
        CHECK((transform * p) == Point(2, 3, 7));
    }
}

TEST_CASE("Sequencing Transforms") {
    SECTION("Applying transforms in sequence") {
        auto p = Point(1, 0, 1);
        auto a = Rotation_X(M_PI / 2);
        auto b = Scaling(5, 5, 5);
        auto c = Translation(10, 5, 7);

        auto p2 = a * p;
        CHECK(p2.isApprox(Point(1, -1, 0)));

        auto p3 = b * p2;
        CHECK(p3.isApprox(Point(5, -5, 0)));

        auto p4 = c * p3;
        CHECK(p4.isApprox(Point(15, 0, 7)));
    }SECTION("Chained transformations must be applied in reverse order") {
        auto p = Point(1, 0, 1);
        auto a = Rotation_X(M_PI / 2);
        auto b = Scaling(5, 5, 5);
        auto c = Translation(10, 5, 7);
        auto t = c * b * a;
        CHECK((t * p).isApprox(Point(15, 0, 7)));
    }

}
