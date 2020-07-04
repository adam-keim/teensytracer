//
// Created by Adam Keim on 6/25/20.
//

#ifndef TEENSYTRACER_CANVAS_H
#define TEENSYTRACER_CANVAS_H

#include "color.h"
#include <ostream>
#include <string>
#include <vector>

class Canvas {
public:
    Canvas(int width, int height);

    ~Canvas();

    int Width() const {
        return m_width;
    }

    int Height() const {
        return m_height;
    }

    Color PixelAt(int x, int y) const;

    void WritePixel(int x, int y, Color const &color);

    friend std::ostream &operator<<(std::ostream &os, const Canvas &c) {
        c.WritePPMHeader(os);
        c.WritePPMPixels(os);
        return os;
    }

protected:
    void WritePPMHeader(std::ostream &out) const;

    void WritePPMPixels(std::ostream &out) const;

private:
    int m_width;
    int m_height;
    std::vector<std::vector<Color>> m_pixels;
};


#endif //TEENSYTRACER_CANVAS_H
