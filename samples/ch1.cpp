//
// Created by Adam Keim on 6/22/20.
//

#include "include/tuple.h"
#include <iostream>

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
    std::cout << "test";
    Projectile p = Projectile(Point(0, 10, 0), Vector(1, 3, 0));
    Environment e = Environment(Vector(0, -.1, 0), Vector(-.01, 0, 0));
    int ticks = 0;
    do {
        tick(e, p);
        ticks += 1;
        std::cout << "Ticks: " << ticks << "\n";
        std::cout << "Position - X: " << p.m_position.x << " Y: " << p.m_position.y << " Z: " << p.m_position.z << "\n";

    } while (p.m_position.y > 0);
}