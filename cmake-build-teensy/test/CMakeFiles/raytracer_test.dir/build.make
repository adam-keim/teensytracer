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
include test/CMakeFiles/raytracer_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/raytracer_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/raytracer_test.dir/flags.make

test/CMakeFiles/raytracer_test.dir/TupleTest.cpp.o: test/CMakeFiles/raytracer_test.dir/flags.make
test/CMakeFiles/raytracer_test.dir/TupleTest.cpp.o: ../test/TupleTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/raytracer_test.dir/TupleTest.cpp.o"
	cd /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/test && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer_test.dir/TupleTest.cpp.o -c /Users/adamkeim/CLionProjects/teensytracer/test/TupleTest.cpp

test/CMakeFiles/raytracer_test.dir/TupleTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer_test.dir/TupleTest.cpp.i"
	cd /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/adamkeim/CLionProjects/teensytracer/test/TupleTest.cpp > CMakeFiles/raytracer_test.dir/TupleTest.cpp.i

test/CMakeFiles/raytracer_test.dir/TupleTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer_test.dir/TupleTest.cpp.s"
	cd /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/adamkeim/CLionProjects/teensytracer/test/TupleTest.cpp -o CMakeFiles/raytracer_test.dir/TupleTest.cpp.s

test/CMakeFiles/raytracer_test.dir/ColorTest.cpp.o: test/CMakeFiles/raytracer_test.dir/flags.make
test/CMakeFiles/raytracer_test.dir/ColorTest.cpp.o: ../test/ColorTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/raytracer_test.dir/ColorTest.cpp.o"
	cd /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/test && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer_test.dir/ColorTest.cpp.o -c /Users/adamkeim/CLionProjects/teensytracer/test/ColorTest.cpp

test/CMakeFiles/raytracer_test.dir/ColorTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer_test.dir/ColorTest.cpp.i"
	cd /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/adamkeim/CLionProjects/teensytracer/test/ColorTest.cpp > CMakeFiles/raytracer_test.dir/ColorTest.cpp.i

test/CMakeFiles/raytracer_test.dir/ColorTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer_test.dir/ColorTest.cpp.s"
	cd /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/adamkeim/CLionProjects/teensytracer/test/ColorTest.cpp -o CMakeFiles/raytracer_test.dir/ColorTest.cpp.s

test/CMakeFiles/raytracer_test.dir/CanvasTest.cpp.o: test/CMakeFiles/raytracer_test.dir/flags.make
test/CMakeFiles/raytracer_test.dir/CanvasTest.cpp.o: ../test/CanvasTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/raytracer_test.dir/CanvasTest.cpp.o"
	cd /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/test && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer_test.dir/CanvasTest.cpp.o -c /Users/adamkeim/CLionProjects/teensytracer/test/CanvasTest.cpp

test/CMakeFiles/raytracer_test.dir/CanvasTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer_test.dir/CanvasTest.cpp.i"
	cd /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/adamkeim/CLionProjects/teensytracer/test/CanvasTest.cpp > CMakeFiles/raytracer_test.dir/CanvasTest.cpp.i

test/CMakeFiles/raytracer_test.dir/CanvasTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer_test.dir/CanvasTest.cpp.s"
	cd /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/adamkeim/CLionProjects/teensytracer/test/CanvasTest.cpp -o CMakeFiles/raytracer_test.dir/CanvasTest.cpp.s

# Object files for target raytracer_test
raytracer_test_OBJECTS = \
"CMakeFiles/raytracer_test.dir/TupleTest.cpp.o" \
"CMakeFiles/raytracer_test.dir/ColorTest.cpp.o" \
"CMakeFiles/raytracer_test.dir/CanvasTest.cpp.o"

# External object files for target raytracer_test
raytracer_test_EXTERNAL_OBJECTS =

test/raytracer_test: test/CMakeFiles/raytracer_test.dir/TupleTest.cpp.o
test/raytracer_test: test/CMakeFiles/raytracer_test.dir/ColorTest.cpp.o
test/raytracer_test: test/CMakeFiles/raytracer_test.dir/CanvasTest.cpp.o
test/raytracer_test: test/CMakeFiles/raytracer_test.dir/build.make
test/raytracer_test: raytracer_lib/libraytracer_lib.a
test/raytracer_test: test/CMakeFiles/raytracer_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable raytracer_test"
	cd /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raytracer_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/raytracer_test.dir/build: test/raytracer_test

.PHONY : test/CMakeFiles/raytracer_test.dir/build

test/CMakeFiles/raytracer_test.dir/clean:
	cd /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/test && $(CMAKE_COMMAND) -P CMakeFiles/raytracer_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/raytracer_test.dir/clean

test/CMakeFiles/raytracer_test.dir/depend:
	cd /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/adamkeim/CLionProjects/teensytracer /Users/adamkeim/CLionProjects/teensytracer/test /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/test /Users/adamkeim/CLionProjects/teensytracer/cmake-build-teensy/test/CMakeFiles/raytracer_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/raytracer_test.dir/depend

