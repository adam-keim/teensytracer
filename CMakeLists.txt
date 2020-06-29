cmake_minimum_required(VERSION 3.16)

if (DO_ARM EQUAL 1)
    set(CMAKE_TOOLCHAIN_FILE cmake/toolchain-arm-none-eabi.cmake)
endif (DO_ARM EQUAL 1)

project(teensytracer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Eigen3_DIR libs/eigen/cmake/)
include_directories(raytracer_lib)
include_directories(${CMAKE_SOURCE_DIR}/libs/eigen/)
add_subdirectory(raytracer_lib)


if (DO_ARM EQUAL 1)
    include_directories(cores/teensy4)
    add_subdirectory(teensy)
    add_subdirectory(libs)
    MESSAGE("Doing Arm")
endif(DO_ARM EQUAL 1)

if (DO_ARM EQUAL 0)
    set(SOURCE_FILES main.cpp)
    add_executable(raytracer_run ${SOURCE_FILES})
    target_link_libraries(raytracer_run raytracer_lib)
    add_subdirectory(test)
    add_subdirectory(samples)
endif (DO_ARM EQUAL 0)

