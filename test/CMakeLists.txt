add_executable(raytracer_test
        TupleTest.cpp
        ColorTest.cpp
        CanvasTest.cpp
        MarixTest.cpp)


target_link_libraries(raytracer_test raytracer_lib)