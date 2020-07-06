//
// Created by Adam Keim on 7/3/20.
//

#ifndef TEENSYTRACER_MATRIX_HELPER_H
#define TEENSYTRACER_MATRIX_HELPER_H

#include <Eigen/Dense>
#include "tuple.h"


Eigen::Matrix4f Translation(float x, float y, float z);

Eigen::Matrix4f Scaling(float x, float y, float z);

Eigen::Matrix4f Rotation_X(float r);

Eigen::Matrix4f Rotation_Y(float r);

Eigen::Matrix4f Rotation_Z(float r);

Eigen::Matrix4f Shearing(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y);

Eigen::Matrix4f ViewTransform(Tuple from, Tuple to, Tuple up);

#endif //TEENSYTRACER_MATRIX_HELPER_H
