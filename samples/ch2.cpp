//
// Created by Adam Keim on 6/25/20.
//

#include "include/tuple.h"
#include "include/canvas.h"
#include "include/color.h"
#include <iostream>
#include <fstream>

struct Projectile {
    Projectile(Tuple const &pos, Tuple const &vel) : m_position(pos), m_velocity(vel) {
    }

    Tuple m_position;
    Tuple m_velocity;
};

struct Environment {
    Environment(Tuple const &gravity, Tuple const &wind) : m_gravity(gravity), m_wind(wind) {
    }

    Tuple m_gravity;
    Tuple m_wind;

};

void tick(Environment const &env, Projectile &proj) {
    proj.m_position = proj.m_position + proj.m_velocity;
    proj.m_velocity = proj.m_velocity + env.m_gravity + env.m_wind;
}


int main() {
    Tuple start = Point(0,1,0);
    Tuple vel = Vector(1, 1.8, 0).Normalize() * 11.25;
    Projectile p = Projectile(start, vel);
    Environment e = Environment(Vector(0, -.1, 0), Vector(-.01, 0, 0));
    Canvas c = Canvas(900, 550);
    do {
        tick(e, p);
        // Plot as 3x3 squares centered at pos
        c.WritePixel(int(p.m_position.x-1), int(550 - p.m_position.y-1), Color(1,1,0));
        c.WritePixel(int(p.m_position.x), int(550 - p.m_position.y-1), Color(1,1,0));
        c.WritePixel(int(p.m_position.x+1), int(550 - p.m_position.y-1), Color(1,1,0));
        c.WritePixel(int(p.m_position.x-1), int(550 - p.m_position.y), Color(1,1,0));
        c.WritePixel(int(p.m_position.x), int(550 - p.m_position.y), Color(1,1,0));
        c.WritePixel(int(p.m_position.x+1), int(550 - p.m_position.y), Color(1,1,0));
        c.WritePixel(int(p.m_position.x-1), int(550 - p.m_position.y+1), Color(1,1,0));
        c.WritePixel(int(p.m_position.x), int(550 - p.m_position.y+1), Color(1,1,0));
        c.WritePixel(int(p.m_position.x+1), int(550 - p.m_position.y+1), Color(1,1,0));
    } while (p.m_position.y > 0);
    std::ofstream out;
    out.open("scene.ppm");
    out << c;
    out.close();
}