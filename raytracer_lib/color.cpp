//
// Created by Adam Keim on 6/22/20.
//

#include "color.h"
#include "math.h"

float Color::red() const {
    return this->x();
}

float Color::green() const {
    return this->y();
}

float Color::blue() const {
    return this->z();
}

Color operator*(Color const &c1, Color const &c2) {
    return Color(c1.red() * c2.red(),
                 c1.green() * c2.green(),
                 c1.blue() * c2.blue());

}

Color operator*(Color const &c, float const &f) {
    return Color(c.red() * f, c.green() * f, c.blue() * f);
}

Color operator+(Color const &c1, Color const &c2) {
    return Color(c1.red() + c2.red(), c1.green() + c2.green(), c1.blue() + c2.blue());
}
//bool operator==(Color const &c1, Color const &c2) {
//    return (c1.red() == c2.red()
//    and c1.blue() == c2.blue()
//    and c1.green() == c2.green());
//}

Color Color::to_clamped_rgb() const {
    int red = fmax(0, fmin(255, ceil(this->red() * 255)));
    int green = fmax(0, fmin(255, ceil(this->green() * 255)));
    int blue = fmax(0, fmin(255, ceil(this->blue() * 255)));
    return Color(red, green, blue);
}

Color Color::to_rgb() const {
    return Color(this->red() * 255, this->green() * 255, this->blue() * 255);
}

