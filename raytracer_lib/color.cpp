//
// Created by Adam Keim on 6/22/20.
//

#include "color.h"

float Color::red() const {
    return this->x;
}

float Color::green() const {
    return this->y;
}

float Color::blue() const {
    return this->z;
}

Color operator * (Color const &c1, Color const &c2) {
    return Color(c1.red() * c2.red(),
            c1.green() * c2.green(),
            c1.blue() * c2.blue());

}