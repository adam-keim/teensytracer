//
// Created by Adam Keim on 6/22/20.
//

#include "include/tuple.h"
#include "math.h"


bool Tuple::IsPoint() const{
    return this->w() == 1.0;
}

bool Tuple::IsVector() const{
    return this->w() == 0.0;
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

Tuple Tuple::reflect(Tuple n) const {
    return (*this - n * 2 * this->dot(n));
}
