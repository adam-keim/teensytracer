//
// Created by Adam Keim on 7/4/20.
//
#include "catch.hpp"
#include "include/light.h"
#include "include/tuple.h"
#include "include/color.h"

TEST_CASE("Creating a light") {
    SECTION("A point light has position and intensity") {
        Color intensity = Color(1, 1, 1);
        Tuple position = Point(0, 0, 0);
        PointLight l = PointLight(position, intensity);
        CHECK(l.position == position);
        CHECK(l.intensity == intensity);
    }
}