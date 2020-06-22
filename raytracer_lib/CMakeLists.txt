project(teensytracer)


set(SOURCE_FILES
        tuple.cpp
        )

add_library(raytracer_lib STATIC ${SOURCE_FILES})
target_include_directories(raytracer_lib PUBLIC include)
