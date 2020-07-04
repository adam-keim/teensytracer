//
// Created by Adam Keim on 6/22/20.
//

#ifndef TEENSYTRACER_COLOR_H
#define TEENSYTRACER_COLOR_H

#include "tuple.h"

class Color : public Tuple {
public:
    Color(float red, float green, float blue) : Tuple(red, green, blue, 0.0f) {};

    float red() const;

    float green() const;

    float blue() const;

    friend Color operator*(Color const &, Color const &);
    friend Color operator*(Color const &, float const &);
    friend Color operator+(Color const &, Color const &);
    //friend bool operator==(Color const &, Color const &);
    Color to_rgb() const;

    Color to_clamped_rgb() const;

    uint16_t to_tft_rgb() const;

};


#endif //TEENSYTRACER_COLOR_H
