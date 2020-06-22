cmake_minimum_required(VERSION 3.16)
project(teensytracer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES main.cpp)
add_executable(raytracer_run ${SOURCE_FILES})

include_directories(raytracer_lib)
target_link_libraries(raytracer_run raytracer_lib)
add_subdirectory(raytracer_lib)
add_subdirectory(test)
add_subdirectory(samples)

