//
// Created by Adam Keim on 7/4/20.
//

#include "catch.hpp"
#include "include/world.h"
#include "include/matrix_helper.h"

TEST_CASE("Basic world operations") {
    SECTION("Creating a world") {
        auto w = World();
        CHECK(w.objects.size() == 0);
        CHECK(w.hasLight == false);

    }SECTION("The default world") {
       auto light = PointLight(Point(-10, 10, -10), Color(1,1,1));
       auto s1 = Sphere();
       s1.material.color = Color(.8, 1.0, 0.6);
       s1.material.diffuse = 0.7;
       s1.material.specular = .2;
       auto s2 = Sphere();
       s2.set_transform(Scaling(.5,.5,.5));
       World w = World::DefaultWorld();
       CHECK(w.light == light);
       CHECK(w.objects[0] == s1);
       CHECK(w.objects[1] == s2);

    }

}
