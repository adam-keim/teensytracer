//
// Created by Adam Keim on 7/3/20.
//

#include "include/ray.h"
#include "include/shapes.h"
#include <iostream>

Tuple Ray::position(float t) const {
    return this->origin + this->direction * t;
}

Intersection hit(std::vector<Intersection> xs) {
    int hit_index = -1;
    for (unsigned int i = 0; i < xs.size(); i++) {
        if (xs[i].t > 0 and (hit_index == -1 or xs[i].t < xs[hit_index].t)) {
            hit_index = i;
        }
    }
    if (hit_index == -1) {
        return Intersection();
    } else {
        return xs[hit_index];
    }
}

Comps Intersection::prepare_computations(Ray ray) const {
   Comps c;
   c.t = this->t;
   c.object = this->object;
   c.point = ray.position(c.t);
   c.eyev = -ray.direction;
   c.normalv = this->object->normal_at(c.point);
   if(c.normalv.dot(c.eyev) < 0) {
       c.inside = true;
       c.normalv = -c.normalv;
   } else {
       c.inside = false;
   }
   return c;

}


Ray Ray::transform(Eigen::Matrix4f t) {
    Tuple new_origin = t * this->origin;
    Tuple new_direction = t * this->direction;
    return Ray(new_origin, new_direction);
}




