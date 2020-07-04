//
// Created by Adam Keim on 6/25/20.
//

#include "include/canvas.h"
#include "include/commonmath.h"

Canvas::Canvas(int width, int height)
        : m_height(height),
          m_width(width),
          m_pixels(width, std::vector<Color>(height, Color(0, 0, 0))) {
}

Canvas::~Canvas() {
    m_pixels.clear();
    m_pixels.shrink_to_fit();
}

Color Canvas::PixelAt(int x, int y) const {
    return m_pixels[x][y];
}

void Canvas::WritePPMHeader(std::ostream &out) const {
    out << "P3\n" << m_width << ' ' << m_height << "\n255\n";

}

void Canvas::WritePPMPixels(std::ostream &out) const {
    int linewidth = 0;
    for (size_t y = 0; y < m_height; y++) {
        bool first = true;
        for (size_t x = 0; x < m_width; x++) {
            Color c = this->PixelAt(x, y).to_clamped_rgb();
            //Write Red:
            int r = c.red();
            if (linewidth + 1 + num_width(r) > 70) {
                out << "\n";
                linewidth = 0;
                first = true;
            }
            if (first) {
                first = false;
            } else {
                out << ' ';
                linewidth++;
            }
            out << r;
            linewidth += num_width(r);

            //Do the same for green
            int g = c.green();
            if (linewidth + 1 + num_width(g) > 70) {
                out << "\n";
                linewidth = 0;
                first = true;
            }
            if (first) {
                first = false;
            } else {
                out << ' ';
                linewidth++;
            }
            out << g;
            linewidth += num_width(g);

            //And finally blue
            int b = c.blue();
            if (linewidth + 1 + num_width(b) > 70) {
                out << "\n";
                linewidth = 0;
                first = true;
            }
            if (first) {
                first = false;
            } else {
                out << ' ';
                linewidth++;
            }
            out << b;
            linewidth += num_width(b);
        }
        out << "\n";
        linewidth = 0;
    }

}

void Canvas::WritePixel(int x, int y, const Color &color) {
    if (x >= m_width || y >= m_height) return;
    m_pixels[x][y] = color;
}