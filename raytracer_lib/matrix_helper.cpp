//
// Created by Adam Keim on 7/3/20.
//

#include "include/matrix_helper.h"

Eigen::Matrix4f Translation(float x, float y, float z) {
    Eigen::Matrix4f t;
    t << 1, 0, 0, x,
            0, 1, 0, y,
            0, 0, 1, z,
            0, 0, 0, 1;
    return t;
}

Eigen::Matrix4f Scaling(float x, float y, float z) {
    Eigen::Matrix4f t;
    t << x, 0, 0, 0,
            0, y, 0, 0,
            0, 0, z, 0,
            0, 0, 0, 1;
    return t;
}

Eigen::Matrix4f Rotation_X(float r) {
    Eigen::Matrix4f t;
    t << 1, 0, 0, 0,
            0, cos(r), -sin(r), 0,
            0, sin(r), cos(r), 0,
            0, 0, 0, 1;
    return t;
}

Eigen::Matrix4f Rotation_Y(float r) {
    Eigen::Matrix4f t;
    t << cos(r), 0, sin(r), 0,
            0, 1, 0, 0,
            -sin(r), 0, cos(r), 0,
            0, 0, 0, 1;
    return t;
}

Eigen::Matrix4f Rotation_Z(float r) {
    Eigen::Matrix4f t;
    t << cos(r), -sin(r), 0, 0,
            sin(r), cos(r), 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1;
    return t;
}

Eigen::Matrix4f Shearing(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y) {
    Eigen::Matrix4f t;
    t << 1, x_y, x_z, 0,
            y_x, 1, y_z, 0,
            z_x, z_y, 1, 0,
            0, 0, 0, 1;
    return t;
}

Eigen::Matrix4f ViewTransform(Tuple from, Tuple to, Tuple up) {
    Tuple forward = (to - from).normalized();
    Tuple up_n = up.normalized();
    Tuple left = forward.cross3(up_n);
    Tuple true_up = left.cross3(forward);
    Eigen::Matrix4f o;
    o << left.x(), left.y(), left.z(), 0,
            true_up.x(), true_up.y(), true_up.z(), 0,
            -forward.x(), -forward.y(), -forward.z(), 0,
            0, 0, 0, 1;
    return o * Translation(-from.x(), -from.y(), -from.z());

}