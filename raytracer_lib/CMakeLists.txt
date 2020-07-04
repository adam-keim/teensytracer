set(SOURCE_FILES
        tuple.cpp
        color.cpp
        canvas.cpp
        ray.cpp
        shapes.cpp
        matrix_helper.cpp)

add_library(raytracer_lib STATIC ${SOURCE_FILES})
target_include_directories(raytracer_lib PUBLIC include)
