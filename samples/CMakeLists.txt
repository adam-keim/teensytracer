# Add an executable for the "Wrapping it up" at the end of each chapter.
add_executable(
        Projectile_Sample ch1.cpp
)
target_link_libraries(Projectile_Sample raytracer_lib)

add_executable(
        Canvas_Sample ch2.cpp
)
target_link_libraries(Canvas_Sample raytracer_lib)

