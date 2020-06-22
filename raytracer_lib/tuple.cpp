//
// Created by Adam Keim on 6/22/20.
//

#include "include/tuple.h"
#include "math.h"


Tuple::Tuple(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

bool Tuple::IsPoint() {
    return this->w == 1.0;
}

bool Tuple::IsVector() {
    return this->w == 0.0;
}

bool operator==(Tuple const &t1, Tuple const &t2) {
    return (
            equal(t1.x, t2.x) &&
            equal(t1.y, t2.y) &&
            equal(t1.z, t2.z) &&
            equal(t1.w, t2.w)
    );
}

Tuple operator+(Tuple const &t1, Tuple const &t2) {
    return Tuple(
            t1.x + t2.x,
            t1.y + t2.y,
            t1.z + t2.z,
            t1.w + t2.w
    );
}

Tuple operator-(Tuple const &t1, Tuple const &t2) {
    return Tuple(
            t1.x - t2.x,
            t1.y - t2.y,
            t1.z - t2.z,
            t1.w - t2.w
    );
}

Tuple operator-(Tuple const &t) {
    return Tuple(
            -t.x,
            -t.y,
            -t.z,
            -t.w
    );
}

Tuple operator*(Tuple const &t, float const c) {
    return Tuple(
            t.x * c,
            t.y * c,
            t.z * c,
            t.w * c
    );
}

Tuple operator/(Tuple const &t, float const c) {
    return Tuple(
            t.x / c,
            t.y / c,
            t.z / c,
            t.w / c
    );
}


float Tuple::Magnitude() {
    return sqrt(
            pow(this->x, 2) +
            pow(this->y, 2) +
            pow(this->z, 2) +
            pow(this->w, 2)
    );
}

Tuple Tuple::Normalize() {
    float m = this->Magnitude();
    return Tuple(
            this->x / m,
            this->y / m,
            this->z / m,
            this->w / m
            );
}

float Tuple::Dot(Tuple const &t) {
    return (
            this->x * t.x +
            this->y * t.y +
            this->z * t.z +
            this->w * t.w
            );
}

Tuple Tuple::Cross(Tuple const &t) {
    return Vector(
            this->y * t.z - this->z * t.y,
            this->z * t.x - this->x * t.z,
            this->x * t.y - this->y * t.x
            );
}

Tuple Point(float x, float y, float z) {
    return Tuple(x, y, z, 1.0);
}

Tuple Vector(float x, float y, float z) {
    return Tuple(x, y, z, 0.0);
}

bool equal(float a, float b) {
    return (fabs(a - b) < EPSILON);
}