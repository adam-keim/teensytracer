//
// Created by Adam Keim on 7/5/20.
//

#ifndef TEENSYTRACER_CAMERA_H
#define TEENSYTRACER_CAMERA_H

#include <Eigen/Dense>
#include "cmath"
#include "ray.h"
#include "canvas.h"
#include "world.h"

class Camera {
public:
    Camera(int hsize, int vsize, float fov);

    int hsize;
    int vsize;
    float fov;
    float pixel_size;
    float half_width;
    float half_height;
    Eigen::Matrix4f transform = Eigen::Matrix4f::Identity();

    Ray ray_for_pixel(int x, int y) const;

    Canvas render(World &world) const;
};


#endif //TEENSYTRACER_CAMERA_H
