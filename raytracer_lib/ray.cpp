//
// Created by Adam Keim on 7/3/20.
//

#include "include/ray.h"
#include <iostream>
Tuple Ray::position(float t) {
    return this->origin + this->direction * t;
}

Intersection hit(std::vector<Intersection> xs) {
    int hit_index = -1;
    for(unsigned int i = 0; i < xs.size(); i++) {
        if(xs[i].t > 0 and (hit_index == -1 or xs[i].t < xs[hit_index].t)) {
            hit_index = i;
        }
    }
    if(hit_index == -1) {
        return Intersection();
    } else {
        return xs[hit_index];
    }
}

Ray Ray::transform(Eigen::Matrix4f t) {
    Tuple new_origin = t * this->origin;
    Tuple new_direction = t * this->direction;
    return Ray(new_origin, new_direction);
}


