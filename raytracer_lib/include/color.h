//
// Created by Adam Keim on 6/22/20.
//

#ifndef TEENSYTRACER_COLOR_H
#define TEENSYTRACER_COLOR_H
#include "tuple.h"

class Color : public Tuple{
public:
    Color(float red, float green, float blue) : Tuple(red, green, blue, 0.0f) {};
    float red() const;
    float green() const;
    float blue() const;
    friend Color operator*(Color const &, Color const &);
};


#endif //TEENSYTRACER_COLOR_H
