//
// Created by Adam Keim on 6/25/20.
//

#ifndef TEENSYTRACER_COMMONMATH_H

int num_width(int num) {
    int digits = 0;
    while (num) {
        num /= 10;
        digits++;
    }
    return digits;
}

#define TEENSYTRACER_COMMONMATH_H

#endif //TEENSYTRACER_COMMONMATH_H
