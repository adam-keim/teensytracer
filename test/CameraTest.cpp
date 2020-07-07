//
// Created by Adam Keim on 7/5/20.
//

#include "catch.hpp"
#include "include/camera.h"
#include "include/tuple.h"
#include "include/matrix_helper.h"
#include "include/ray.h"
#include "include/world.h"
#include "Eigen/Dense"

TEST_CASE("Camera Implementation") {
    SECTION("Constructing a camera") {
        int hsize = 160;
        int vsize = 120;
        float field_of_view = M_PI / 2;
        Camera c = Camera(hsize, vsize, field_of_view);
        CHECK(c.hsize == 160);
        CHECK(c.vsize == 120);
        CHECK(equal(M_PI / 2, c.fov));
        CHECK(c.transform == Eigen::Matrix4f::Identity());
    }SECTION("The pixel size for a horizontal canvas") {
        Camera c = Camera(200, 125, M_PI / 2);
        CHECK(equal(c.pixel_size, 0.01));
    }SECTION("The pixel size for a vertical canvas") {
        Camera c = Camera(125, 200, M_PI / 2);
        CHECK(equal(c.pixel_size, 0.01));
    }
}

TEST_CASE("Ray for pixel") {
    SECTION("Constructing a ray through the center of the canvas") {
        Camera c = Camera(201, 101, M_PI / 2);
        Ray r = c.ray_for_pixel(100, 50);
        CHECK(r.origin == Point(0, 0, 0));
        CHECK(r.direction.isApprox(Vector(0, 0, -1)));
    } SECTION("Constructing a ray through a corner of the canvas") {
        Camera c = Camera(201, 101, M_PI / 2);
        Ray r = c.ray_for_pixel(0, 0);
        CHECK(r.origin == Point(0, 0, 0));
        CHECK(r.direction.isApprox(Vector(0.66519, 0.33259, -0.66851)));
    } SECTION("Constructing a ray when the camera is transformed") {
        Camera c = Camera(201, 101, M_PI / 2);
        c.transform = Rotation_Y(M_PI / 4) * Translation(0, -2, 5);
        Ray r = c.ray_for_pixel(100, 50);
        CHECK(r.origin.isApprox(Point(0, 2, -5)));
        CHECK(r.direction.isApprox(Vector(sqrt(2)/2, 0, -sqrt(2)/2)));
    }
}

TEST_CASE("Rendering the world with a camera") {
    SECTION("Rendering a world with a camera") {
        auto w = World::DefaultWorld();
        auto c = Camera(11, 11, M_PI / 2);
        auto from = Point(0, 0, -5);
        auto to = Point(0, 0, 0);
        auto up = Vector(0, 1, 0);
        c.transform = ViewTransform(from, to, up);
        auto image = c.render(w);
        std::cout << image.PixelAt(5,5);
        CHECK(image.PixelAt(5, 5).isApprox(Color(0.38066, 0.47583, 0.2855)));
    }
}
