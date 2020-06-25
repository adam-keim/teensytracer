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
        Color red = Color(1,0,0);
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
        std::cout << c;
        CHECK(ostr.str().substr(0, 11) == "P3\n3 5\n255\n");
    } SECTION("Creating pixel Data") {

    }
}