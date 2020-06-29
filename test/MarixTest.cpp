//
// Created by Adam Keim on 6/29/20.
//
#include <Eigen/Dense>
#include "catch.hpp"

TEST_CASE("Matrix Creation") {
    Eigen::Matrix4f m;
    m << 1,2,3,4,
        5.5,6.5,7.5,8.5,
        9,10,11,12,
        13.5,14.5,15.5,16.5;
    CHECK(m(0,0) == 1);
    CHECK(m(0,3) == 4);
    CHECK(m(1,0) == 5.5);
    CHECK(m(1,2) == 7.5);
    CHECK(m(2,2) == 11);
    CHECK(m(3,0) == 13.5);
    CHECK(m(3,2) == 15.5);
}
