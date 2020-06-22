//
// Created by Adam Keim on 6/22/20.
//

#ifndef TEENSYTRACER_TUPLE_H
#define TEENSYTRACER_TUPLE_H


class Tuple {
public:
    float x, y, z, w;
    Tuple(float x, float y, float z, float w);
    bool IsPoint();
    bool IsVector();
};


#endif //TEENSYTRACER_TUPLE_H
