//
// Created by Adam Keim on 6/22/20.
//

#ifndef TEENSYTRACER_TUPLE_H
#define TEENSYTRACER_TUPLE_H
#include <Eigen/Dense>
#define EPSILON .001
bool equal(float a, float b);

class Tuple : public Eigen::Vector4f {
    using Eigen::Vector4f::Vector4f;
public:
    Tuple reflect(Tuple n) const;
    bool IsPoint() const;
    bool IsVector() const;
};

Tuple Point(float x, float y, float z);

Tuple Vector(float x, float y, float z);

#endif //TEENSYTRACER_TUPLE_H
