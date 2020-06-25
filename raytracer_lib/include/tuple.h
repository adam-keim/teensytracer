//
// Created by Adam Keim on 6/22/20.
//

#ifndef TEENSYTRACER_TUPLE_H
#define TEENSYTRACER_TUPLE_H

#define EPSILON .001

bool equal(float a, float b);

class Tuple {
public:
    float x, y, z, w;

    Tuple(float x, float y, float z, float w);

    bool IsPoint() const;


    bool IsVector() const;

    float Magnitude();

    Tuple Normalize();

    float Dot(Tuple const &);

    Tuple Cross(Tuple const &);

    friend bool operator==(Tuple const &, Tuple const &);

    friend Tuple operator+(Tuple const &, Tuple const &);

    friend Tuple operator-(Tuple const &, Tuple const &);

    friend Tuple operator-(Tuple const &);

    friend Tuple operator*(Tuple const &, float const);

    friend Tuple operator/(Tuple const &, float const);

    inline Tuple &operator=(Tuple const &) = default;
};

Tuple Point(float x, float y, float z);

Tuple Vector(float x, float y, float z);

#endif //TEENSYTRACER_TUPLE_H
