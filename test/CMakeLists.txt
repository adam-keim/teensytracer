cmake_minimum_required(VERSION 3.16)
project(teensytracer)

add_executable(raytracer_test
        TupleTest.cpp)


target_link_libraries(raytracer_test raytracer_lib)