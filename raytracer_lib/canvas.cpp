//
// Created by Adam Keim on 6/25/20.
//

#include "include/canvas.h"

Canvas::Canvas(int width, int height)
        : m_height(height),
          m_width(width),
          m_pixels(nullptr) {
    m_pixels = (Color*)calloc(width * height, sizeof(Color));
}

Canvas::~Canvas() {
    if (m_pixels != nullptr) {
        free(m_pixels);
        m_pixels = nullptr;
    }
}

Color Canvas::PixelAt(int x, int y) const {
    return m_pixels[x + m_width * y];
}

void Canvas::WritePPMHeader(std::ostream &out) const {
    out << "P3\n" << m_height << ' ' << m_width << "\n255\n";

}

void Canvas::WritePixel(int x, int y, const Color &color) {
    if (x >= m_width || y >= m_height) return;
    m_pixels[x + m_width * y] = color;
}