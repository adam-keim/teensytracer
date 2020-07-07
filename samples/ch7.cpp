//
// Created by Adam Keim on 7/5/20.
//


#include "include/tuple.h"
#include "include/canvas.h"
#include "include/color.h"
#include "include/light.h"
#include "include/matrix_helper.h"
#include "include/world.h"
#include "include/shapes.h"
#include "include/camera.h"
#include <iostream>
#include <fstream>

int x_width = 1280 * 4;
int y_height = 720 * 4;


int main() {
    World w = World();
    w.light = PointLight(Point(-10, 10, -10), Color(1, 1, 1));

    std::unique_ptr<Shape> floor_sphere = std::make_unique<Sphere>();
    floor_sphere->set_transform(Scaling(10, .01, 10));
    floor_sphere->material = Material();
    floor_sphere->material.color = Color(1, 0.9, 0.9);
    floor_sphere->material.specular = 0;
    w.addObject(std::move(floor_sphere));

    std::unique_ptr<Shape> left_wall = std::make_unique<Sphere>();
    left_wall->transform = Translation(0, 0, 5) *
                          Rotation_Y(-M_PI / 4) * Rotation_X(M_PI / 2) *
                          Scaling(10, 0.01, 10);
    left_wall->material = w.objects[0]->material;
    w.addObject(std::move(left_wall));


    std::unique_ptr<Shape> right_wall = std::make_unique<Sphere>();
    right_wall->transform = Translation(0, 0, 5) *
                           Rotation_Y(M_PI / 4) * Rotation_X(M_PI / 2) *
                           Scaling(10, 0.01, 10);
    right_wall->material = w.objects[0]->material;
    w.addObject(std::move(right_wall));

    std::unique_ptr<Shape> middle = std::make_unique<Sphere>();
    middle->transform = Translation(-0.5, 1, 0.5);
    middle->material = Material();
    middle->material.color = Color(0.1, 1, 0.5);
    middle->material.diffuse = 0.7;
    middle->material.specular = 0.3;
    w.addObject(std::move(middle));

    std::unique_ptr<Shape> right = std::make_unique<Sphere>();
    right->transform = Translation(1.5, 0.5, -0.5) * Scaling(0.5, 0.5, 0.5);
    right->material = Material();
    right->material.color = Color(0.5, 1, 0.1);
    right->material.diffuse = 0.7;
    right->material.specular = 0.3;
    w.addObject(std::move(right));


    std::unique_ptr<Shape> left = std::make_unique<Sphere>();
    left->transform = Translation(-1.5, 0.33, -0.75) * Scaling(0.33, 0.33, 0.33);
    left->material = Material();
    left->material.color = Color(1, 0.8, 0.1);
    left->material.diffuse = 0.7;
    left->material.specular = 0.3;
    w.addObject(std::move(left));

    Camera c = Camera(x_width, y_height, M_PI / 3);
    c.transform = ViewTransform(Point(0, 1.5, -5), Point(0, 1, 0), Vector(0, 1, 0));
    Canvas output = c.render(w);
    std::ofstream out;
    out.open("scene.ppm");
    out << output;
    out.close();


}