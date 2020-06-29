//
// Created by Adam Keim on 6/22/20.
//

#include "catch.hpp"
#include "include/tuple.h"
#include "include/color.h"

TEST_CASE("Color Creation") {
    Color c = Color(-.5, .4, 1.7);
    CHECK(equal(c.red(), -.5));
    CHECK(equal(c.green(), .4));
    CHECK(equal(c.blue(), 1.7));
}

TEST_CASE("Color Operations") {
    SECTION("Adding Colors") {
        Color c1 = Color(0.9, 0.6, 0.75);
        Color c2 = Color(0.7, 0.1, 0.25);
        CHECK((c1 + c2).isApprox(Color(1.6, 0.7, 1.0)));
    }SECTION("Subtracting Colors") {
        Color c1 = Color(0.9, 0.6, 0.75);
        Color c2 = Color(0.7, 0.1, 0.25);
        CHECK((c1 - c2).isApprox(Color(0.2, 0.5, 0.5)));
    }SECTION("Color * Scalar") {
        Color c = Color(0.2, 0.3, 0.4);
        CHECK(c * 2 == Color(0.4, 0.6, 0.8));

    }SECTION("Multiplying Colors") {
        Color c1 = Color(1, 0.2, 0.4);
        Color c2 = Color(0.9, 1, 0.1);
        CHECK((c1 * c2).isApprox(Color(0.9, 0.2, 0.04)));
    }
}