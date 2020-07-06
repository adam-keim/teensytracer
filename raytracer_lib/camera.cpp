//
// Created by Adam Keim on 7/5/20.
//

#include "include/camera.h"

Camera::Camera(int hsize, int vsize, float fov) : hsize(hsize), vsize(vsize), fov(fov) {
    float half_view = tan(fov / 2);
    float aspect = (float)hsize / (float)vsize;
    if(aspect >= 1) {
        half_width = half_view;
        half_height = half_view / aspect;
    } else {
        half_width = half_view * aspect;
        half_height = half_view;
    }
    pixel_size = (half_width * 2) / hsize;

}

Ray Camera::ray_for_pixel(int x, int y) const {
    float x_off = ((float)x + .5f) * this->pixel_size;
    float y_off = ((float)y + .5f) * this->pixel_size;
    float world_x = this->half_width - x_off;
    float world_y = this->half_height - y_off;
    Tuple pixel = this->transform.inverse() * Point(world_x, world_y, -1);
    Tuple origin = this->transform.inverse() * Point(0,0,0);
    Tuple direction = (pixel - origin).normalized();
    return Ray(origin,direction);
}

Canvas Camera::render(World world) const {
    Canvas image = Canvas(this->hsize, this->vsize);
    for(int y = 0; y < this->vsize; y++) {
        for(int x = 0; x < this->hsize; x++) {
            Ray ray = this->ray_for_pixel(x, y);
            Color c = world.color_at(ray);
            image.WritePixel(x, y, c);
        }
    }
    return image;
}



