# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/adamkeim/CLionProjects/teensytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy

# Include any dependencies generated for this target.
include CMakeFiles/raytracer_run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/raytracer_run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raytracer_run.dir/flags.make

CMakeFiles/raytracer_run.dir/main.cpp.o: CMakeFiles/raytracer_run.dir/flags.make
CMakeFiles/raytracer_run.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/raytracer_run.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer_run.dir/main.cpp.o -c /Users/adamkeim/CLionProjects/teensytracer/main.cpp

CMakeFiles/raytracer_run.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer_run.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/adamkeim/CLionProjects/teensytracer/main.cpp > CMakeFiles/raytracer_run.dir/main.cpp.i

CMakeFiles/raytracer_run.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer_run.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/adamkeim/CLionProjects/teensytracer/main.cpp -o CMakeFiles/raytracer_run.dir/main.cpp.s

# Object files for target raytracer_run
raytracer_run_OBJECTS = \
"CMakeFiles/raytracer_run.dir/main.cpp.o"

# External object files for target raytracer_run
raytracer_run_EXTERNAL_OBJECTS =

raytracer_run: CMakeFiles/raytracer_run.dir/main.cpp.o
raytracer_run: CMakeFiles/raytracer_run.dir/build.make
raytracer_run: raytracer_lib/libraytracer_lib.a
raytracer_run: CMakeFiles/raytracer_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable raytracer_run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raytracer_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raytracer_run.dir/build: raytracer_run

.PHONY : CMakeFiles/raytracer_run.dir/build

CMakeFiles/raytracer_run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raytracer_run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raytracer_run.dir/clean

CMakeFiles/raytracer_run.dir/depend:
	cd /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/adamkeim/CLionProjects/teensytracer /Users/adamkeim/CLionProjects/teensytracer /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/CMakeFiles/raytracer_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/raytracer_run.dir/depend

