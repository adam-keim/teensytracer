//
// Created by Adam Keim on 7/4/20.
//

#include "catch.hpp"
#include "include/material.h"
#include "include/light.h"

TEST_CASE("Creating a material") {
    SECTION("The default material") {
        auto m = Material();
        CHECK(m.color == Color(1, 1, 1));
        CHECK(m.ambient == 0.1f);
        CHECK(m.diffuse == 0.9f);
        CHECK(m.specular == 0.9f);
        CHECK(m.shininess == 200.0);
    }
}

TEST_CASE("Lighting a material") {
    auto m = Material();
    auto pos = Point(0, 0, 0);
    SECTION("Lighting with the eye between the light and the surface") {
        auto eyev = Vector(0, 0, -1);
        auto normalv = Vector(0, 0, -1);
        auto light = PointLight(Point(0, 0, -10), Color(1, 1, 1));
        Color result = m.lighting(light, pos, eyev, normalv);
        CHECK(result == Color(1.9, 1.9, 1.9));
    }
    SECTION("Lighting with the eye between light and surface, eye offset 45°") {
        auto eyev = Vector(0, sqrt(2) / 2, -sqrt(2) / 2);
        auto normalv = Vector(0, 0, -1);
        auto light = PointLight(Point(0, 0, -10), Color(1, 1, 1));
        auto result = m.lighting(light, pos, eyev, normalv);
        CHECK(result == Color(1.0, 1.0, 1.0));
    }
    SECTION("Lighting with eye opposite surface, light offset 45°") {
        auto eyev = Vector(0, 0, -1);
        auto normalv = Vector(0, 0, -1);
        auto light = PointLight(Point(0, 10, -10), Color(1, 1, 1));
        auto result = m.lighting(light, pos, eyev, normalv);
        CHECK(result.isApprox(Color(0.7364, 0.7364, 0.7364)));
    }
    SECTION("Lighting with eye in the path of the reflection vector") {
        auto eyev = Vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
        auto normalv = Vector(0, 0, -1);
        auto light = PointLight(Point(0, 10, -10), Color(1, 1, 1));
        auto result = m.lighting(light, pos, eyev, normalv);
        CHECK(result.isApprox(Color(1.6364, 1.6364, 1.6364)));
    }
    SECTION("Lighting with the light behind the surface") {
        auto eyev = Vector(0, 0, -1);
        auto normalv = Vector(0, 0, -1);
        auto light = PointLight(Point(0, 0, 10), Color(1, 1, 1));
        auto result = m.lighting(light, pos, eyev, normalv);
        CHECK(result.isApprox(Color(0.1, 0.1, 0.1)));
    }
}
