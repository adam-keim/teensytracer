//
// Created by Adam Keim on 7/3/20.
//

#include "include/ray.h"

Tuple Ray::position(float t) {
    return this->origin + this->direction * t;
}

