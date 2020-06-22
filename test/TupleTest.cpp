//
// Created by Adam Keim on 6/22/20.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "include/tuple.h"

TEST_CASE("Tuple Creation") {
    SECTION("Point Tuple") {
        Tuple t = Tuple(4.3, -4.2, 3.1, 1.0);
        CHECK(t.x == 4.3f);
        CHECK(t.y == -4.2f);
        CHECK(t.z == 3.1f);
        CHECK(t.w == 1.0f);
        CHECK(t.IsPoint());
        CHECK(!t.IsVector());
    }

    SECTION("Vector Tuple") {
        Tuple t = Tuple(4.3, -4.2, 3.1, 0.0);
        CHECK(t.x == 4.3f);
        CHECK(t.y == -4.2f);
        CHECK(t.z == 3.1f);
        CHECK(t.w == 0.0f);
        CHECK(!t.IsPoint());
        CHECK(t.IsVector());
    }

    SECTION("Create Point") {
        Tuple p = Point(4, -4, 3);
        Tuple t = Tuple(4, -4, 3, 1);
        CHECK(p == t);
    }

    SECTION("Create Vector") {
        Tuple v = Vector(4, -4, 3);
        Tuple t = Tuple(4, -4, 3, 0);
        CHECK(v == t);
    }
}

TEST_CASE("Tuple Basic Operations") {
    SECTION("Adding Tuples") {
        Tuple a1 = Tuple(3, -2, 5, 1);
        Tuple a2 = Tuple(-2, 3, 1, 0);
        CHECK(a1 + a2 == Tuple(1, 1, 6, 1));
    }

    SECTION("Subtracting Tuples") {
        SECTION("Point - Point -> Vector") {
            Tuple p1 = Point(3, 2, 1);
            Tuple p2 = Point(5, 6, 7);
            CHECK(p1 - p2 == Vector(-2, -4, -6));
        }SECTION("Point - Vector -> Point") {
            Tuple p1 = Point(3, 2, 1);
            Tuple p2 = Vector(5, 6, 7);
            CHECK(p1 - p2 == Point(-2, -4, -6));
        }
    }SECTION("Negating Tuples") {
        SECTION("Zero Sub") {
            Tuple zero = Vector(0, 0, 0);
            Tuple v = Vector(1, 2, 3);
            CHECK(zero - v == Vector(-1, -2, -3));
        }SECTION("Tuple negation") {
            Tuple a = Tuple(1, -2, 3, -4);
            CHECK(-a == Tuple(-1, 2, -3, 4));
        }
    }SECTION("Scalar Mult + Div") {
        SECTION("Tuple * Scalar") {
            Tuple a = Tuple(1, -2, 3, -4);
            CHECK (a * 3.5 == Tuple(3.5, -7, 10.5, -14));
        }SECTION("Tuple * Fraction") {
            Tuple a = Tuple(1, -2, 3, -4);
            CHECK (a * 0.5 == Tuple(0.5, -1, 1.5, -2));
        }SECTION("Tuple / Scalar") {
            Tuple a = Tuple(1, -2, 3, -4);
            CHECK(a / 2 == Tuple(0.5, -1, 1.5, -2));
        }
    }
}

TEST_CASE("Tuple advanced operations") {
    SECTION("Magnitude") {
        Tuple a1 = Vector(1, 0, 0);
        CHECK(equal(a1.Magnitude(), 1));
        Tuple a2 = Vector(0, 1, 0);
        CHECK(equal(a2.Magnitude(), 1));
        Tuple a3 = Vector(0, 0, 1);
        CHECK(equal(a3.Magnitude(), 1));
        Tuple a4 = Vector(1, 2, 3);
        CHECK(equal(a4.Magnitude(), sqrt(14)));
        Tuple a5 = Vector(-1, -2, -3);
        CHECK(equal(a5.Magnitude(), sqrt(14)));

    }SECTION("Normalize") {
        Tuple v1 = Vector(4, 0, 0);
        CHECK(v1.Normalize() == Vector(1, 0, 0));

        Tuple v2 = Vector(1, 2, 3);
        CHECK(v2.Normalize() == Vector(0.26726, 0.53452, 0.80178));

        CHECK(equal(v2.Normalize().Magnitude(), 1));
    }SECTION("Dot Product") {
        Tuple a = Vector(1, 2, 3);
        Tuple b = Vector(2, 3, 4);
        CHECK(equal(a.Dot(b), 20));
    }SECTION("Cross Product") {
        Tuple a = Vector(1,2,3);
        Tuple b = Vector(2,3,4);
        CHECK(a.Cross(b) == Vector(-1, 2, -1));
        CHECK(b.Cross(a) == Vector(1, -2, 1));
    }
}