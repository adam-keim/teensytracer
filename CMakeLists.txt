cmake_minimum_required(VERSION 3.16)

if (DO_ARM EQUAL 1)
    set(CMAKE_TOOLCHAIN_FILE cmake/toolchain-arm-none-eabi.cmake)
endif (DO_ARM EQUAL 1)

project(teensytracer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



if (DO_ARM EQUAL 1)
    include_directories(cores/teensy4)
    include_directories(raytracer_lib)
    add_subdirectory(raytracer_lib)
    add_subdirectory(teensy)
    add_subdirectory(libs)
    set(SOURCE_FILES main.cpp)
    add_executable(raytracer_run ${SOURCE_FILES})
    target_link_libraries(raytracer_run raytracer_lib)
    MESSAGE("Doing Arm")
endif(DO_ARM EQUAL 1)

if (DO_ARM EQUAL 0)

    include_directories(raytracer_lib)
    add_subdirectory(raytracer_lib)
    set(SOURCE_FILES main.cpp)
    add_executable(raytracer_run ${SOURCE_FILES})
    target_link_libraries(raytracer_run raytracer_lib)
    add_subdirectory(test)
    add_subdirectory(samples)
endif (DO_ARM EQUAL 0)

