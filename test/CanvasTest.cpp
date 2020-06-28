//
// Created by Adam Keim on 6/25/20.
//

#include "catch.hpp"
#include "include/canvas.h"
#include <iostream>
#include <string>
#include <sstream>

TEST_CASE("Canvas Creation") {
    SECTION("Creation") {
        Canvas c = Canvas(10, 20);
        CHECK(c.Height() == 20);
        CHECK(c.Width() == 10);
        const Color black = Color(0, 0, 0);
        for (int x = 0; x < c.Width(); x++) {
            for (int y = 0; y < c.Height(); y++) {
                CHECK(c.PixelAt(x, y) == black);
            }
        }
    }SECTION("Setting a pixel") {
        Canvas c = Canvas(10, 20);
        Color red = Color(1, 0, 0);
        const Color black = Color(0, 0, 0);
        c.WritePixel(2, 3, red);
        CHECK(c.PixelAt(2, 3) == red);
    }
}

TEST_CASE("Canvas PPM Output") {
    SECTION("Creating PPM Header") {
        Canvas c = Canvas(5, 3);
        std::stringstream ostr;
        ostr << c;
        CHECK(ostr.str().substr(0, 11) == "P3\n3 5\n255\n");
    } SECTION("Creating pixel Data") {
        Canvas c = Canvas(5, 3);
        Color c1 = Color(1.5, 0, 0);
        Color c2 = Color(0, 0.5, 0);
        Color c3 = Color(-.5, 0, 1);
        c.WritePixel(0, 0, c1);
        c.WritePixel(2, 1, c2);
        c.WritePixel(4, 2, c3);
        std::stringstream ostr;
        ostr << c;
        CHECK(ostr.str().substr(11, 95) ==
              "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 255");

    }SECTION("Checking Long lines") {
        Canvas c = Canvas(10, 2);
        for (int x = 0; x < c.Width(); x++) {
            for (int y = 0; y < c.Height(); y++) {
                c.WritePixel(x, y, Color(1, .8, .6));
            }
        }
        std::stringstream ostr;
        ostr << c;
        CHECK(ostr.str().substr(12, 239) == "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n153 255 204 153 255 204 153 255 204 153 255 204 153");
    }SECTION("Checking newline ending") {
        Canvas c = Canvas(5, 3);
        std::stringstream ostr;
        ostr << c;
        CHECK(ostr.str().substr(100) == "\n");
    }
}