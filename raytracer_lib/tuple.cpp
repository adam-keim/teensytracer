//
// Created by Adam Keim on 6/22/20.
//

#include "include/tuple.h"

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
