project(teensytracer)

set(HEADER_FILES
        include/tuple.h
        )

set(SOURCE_FILES
        tuple.cpp
        )
include_directories(include/)

add_library(raytracer_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})