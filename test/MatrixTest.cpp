//
// Created by Adam Keim on 6/29/20.
//
#include <Eigen/Dense>
#include "catch.hpp"
#include "include/tuple.h"
#include <iostream>

TEST_CASE("Matrix Creation") {
    SECTION("4x4 Matrix") {
        Eigen::Matrix4f m;
        m << 1, 2, 3, 4,
                5.5, 6.5, 7.5, 8.5,
                9, 10, 11, 12,
                13.5, 14.5, 15.5, 16.5;
        CHECK(m(0, 0) == 1);
        CHECK(m(0, 3) == 4);
        CHECK(m(1, 0) == 5.5);
        CHECK(m(1, 2) == 7.5);
        CHECK(m(2, 2) == 11);
        CHECK(m(3, 0) == 13.5);
        CHECK(m(3, 2) == 15.5);
    }SECTION("3x3 Matrix") {
        Eigen::Matrix3f m;
        m << -3, 5, 0,
                1, -2, -7,
                0, 1, 1;
        CHECK(m(0, 0) == -3);
        CHECK(m(1, 1) == -2);
        CHECK(m(2, 2) == 1);
    }SECTION("2x2 Matrix") {
        Eigen::Matrix2f m;
        m << -3, 5,
                1, -2;
        CHECK(m(0, 0) == -3);
        CHECK(m(0, 1) == 5);
        CHECK(m(1, 0) == 1);
        CHECK(m(1, 1) == -2);
    }
}

TEST_CASE("Matrix Equality") {
    SECTION("Matrices are identical") {
        Eigen::Matrix4i m1;
        Eigen::Matrix4i m2;
        m1 << 1, 2, 3, 4,
                5, 6, 7, 8,
                9, 8, 7, 6,
                5, 4, 3, 2;
        m2 << 1, 2, 3, 4,
                5, 6, 7, 8,
                9, 8, 7, 6,
                5, 4, 3, 2;
        CHECK(m1 == m2);
    }SECTION("Matrices are not identical") {
        Eigen::Matrix4i m1;
        Eigen::Matrix4i m2;
        m1 << 1, 2, 3, 4,
                5, 6, 7, 8,
                9, 8, 7, 6,
                5, 4, 3, 2;
        m2 << 2, 2, 3, 4,
                5, 6, 7, 8,
                9, 8, 7, 6,
                5, 4, 3, 2;
        CHECK(m1 != m2);
    }
}

TEST_CASE("Multiplying Matrices") {
    SECTION("Matrix * Matrix") {
        Eigen::Matrix4f ma;
        Eigen::Matrix4f mb;
        Eigen::Matrix4f mr;
        ma << 1, 2, 3, 4,
                5, 6, 7, 8,
                9, 8, 7, 6,
                5, 4, 3, 2;
        mb << -2, 1, 2, 3,
                3, 2, 1, -1,
                4, 3, 6, 5,
                1, 2, 7, 8;


        mr << 20, 22, 50, 48,
                44, 54, 114, 108,
                40, 58, 110, 102,
                16, 26, 46, 42;

        CHECK(ma * mb == mr);

    }SECTION("Matrix * Tuple") {
        Eigen::Matrix4f m;
        m << 1, 2, 3, 4,
                2, 4, 4, 2,
                8, 6, 4, 1,
                0, 0, 0, 1;
        Tuple tuple = Tuple(1, 2, 3, 1);
        CHECK(m * tuple == Tuple(18, 24, 33, 1));

    }
}

TEST_CASE("Identity Matrix") {
    SECTION("Matrix") {
        Eigen::Matrix4f m;
        m << 0, 1, 2, 4,
                1, 2, 4, 8,
                2, 4, 8, 16,
                4, 8, 16, 32;
        auto i = Eigen::Matrix4f::Identity();
        CHECK(m * i == m);

    }SECTION("Tuple") {
        auto m = Eigen::Matrix4f::Identity();
        Tuple a = Tuple(1, 2, 3, 4);
        CHECK(m * a == a);
    }
}

TEST_CASE("Transposing Matrices") {
    SECTION("Dense Matrix") {
        Eigen::Matrix4f m1;
        Eigen::Matrix4f m2;
        m1 << 0, 9, 3, 0,
                9, 8, 0, 8,
                1, 8, 5, 3,
                0, 0, 5, 8;
        m2 << 0, 9, 1, 0,
                9, 8, 8, 0,
                3, 0, 5, 5,
                0, 8, 3, 8;
        CHECK(m2 == m1.transpose());
    }SECTION("Identity Matrix") {
        auto m = Eigen::Matrix4f::Identity();
        CHECK(m.transpose() == m);
    }
}

TEST_CASE("Inversion") {
    SECTION("2x2 Determinant") {
        Eigen::Matrix2f m;
        m << 1, 5,
                -3, 2;
        CHECK(m.determinant() == 17);
    }SECTION("3x3 Determinant") {
        Eigen::Matrix3f m;
        m << 1, 2, 6,
                -5, 8, -4,
                2, 6, 4;
        CHECK(m.determinant() == -196);
    }SECTION("4x4 Determinant") {
        Eigen::Matrix4f m;
        m << -2, -8, 3, 5,
                -3, 1, 7, 3,
                1, 2, -9, 6,
                -6, 7, 7, -9;
        CHECK(m.determinant() == -4071);
    }SECTION("Check Invertibility POS") {
        Eigen::Matrix4f m;
        m << 6, 4, 4, 4,
                5, 5, 7, 6,
                4, -9, 3, -7,
                9, 1, 7, -6;
        CHECK(m.determinant() == -2120);
        CHECK_NOTHROW(m.inverse());

    }SECTION("Check Invertibiilty NEG") {
        Eigen::Matrix4f m;
        //| -4 | 2 | -2 | -3 |
        //| 9 | 6 | 2 | 6 |
        //| 0 | -5 | 1 | -5 |
        //| 0 | 0 | 0 | 0 |
        m << -4, 2, -2, -3,
                9, 6, 2, 6,
                0, -5, 1, -5,
                0, 0, 0, 0;
        CHECK(m.determinant() == 0);
        CHECK(m.inverse().hasNaN());
    }SECTION("Check Inverse") {
        Eigen::Matrix4d a;
        a << -5, 2, 6, -8,
                1, -5, 1, 8,
                7, 7, -6, -7,
                1, -3, 7, 4;
        auto b1 = a.inverse();
        Eigen::Matrix4d b2;
        b2 << 0.21805, 0.45113, 0.24060, -0.04511,
                -0.80827, -1.45677, -0.44361, 0.52068,
                -0.07895, -0.22368, -0.05263, 0.19737,
                -0.52256, -0.81391, -0.30075, 0.30639;
        CHECK(a.determinant() == 532);
        CHECK(b2.isApprox(b1, .00005));
    }SECTION("Even More inverses") {
        Eigen::Matrix4f a, b;
        a << 8, -5, 9, 2,
                7, 5, 6, 1,
                -6, 0, 9, 6,
                -3, 0, -9, -4;
        b << -0.15385, -0.15385, -0.28205, -0.53846,
                -0.07692, 0.12308, 0.02564, 0.03077,
                0.35897, 0.35897, 0.43590, 0.92308,
                -0.69231, -0.69231, -0.76923, -1.92308;
        CHECK(a.inverse().isApprox(b, .00005));
    }SECTION("A third inversion") {
        Eigen::Matrix4f a, b;

        a << 9, 3, 0, 9,
                -5, -2, -6, -3,
                -4, 9, 6, 4,
                -7, 6, 6, 2;
        b << -0.04074, -0.07778, 0.14444, -0.22222,
                -0.07778, 0.03333, 0.36667, -0.33333,
                -0.02901, -0.14630, -0.10926, 0.12963,
                0.17778, 0.06667, -0.26667, 0.33333;
        CHECK(a.inverse().isApprox(b, .00005));
    }SECTION("Multiplication by inverse") {

        Eigen::Matrix4f a, b;
        a << 3 , -9 , 7 , 3 ,
           3 , -8 , 2 , -9 ,
           -4 , 4 , 4 , 1 ,
           -6 , 5 , -1 , 1;
        b << 8 , 2 , 2 , 2 ,
           3 , -1 , 7 , 0 ,
           7 , 0 , 5 , 4 ,
           6 , -2 , 0 , 5;
        auto c = a * b;
        CHECK((c * b.inverse()).isApprox(a));
    }
}
