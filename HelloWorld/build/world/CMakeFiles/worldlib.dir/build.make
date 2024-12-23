# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /testcode/HelloWorld

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /testcode/HelloWorld/build

# Include any dependencies generated for this target.
include world/CMakeFiles/worldlib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include world/CMakeFiles/worldlib.dir/compiler_depend.make

# Include the progress variables for this target.
include world/CMakeFiles/worldlib.dir/progress.make

# Include the compile flags for this target's objects.
include world/CMakeFiles/worldlib.dir/flags.make

world/CMakeFiles/worldlib.dir/world.cpp.o: world/CMakeFiles/worldlib.dir/flags.make
world/CMakeFiles/worldlib.dir/world.cpp.o: ../world/world.cpp
world/CMakeFiles/worldlib.dir/world.cpp.o: world/CMakeFiles/worldlib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/testcode/HelloWorld/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object world/CMakeFiles/worldlib.dir/world.cpp.o"
	cd /testcode/HelloWorld/build/world && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT world/CMakeFiles/worldlib.dir/world.cpp.o -MF CMakeFiles/worldlib.dir/world.cpp.o.d -o CMakeFiles/worldlib.dir/world.cpp.o -c /testcode/HelloWorld/world/world.cpp

world/CMakeFiles/worldlib.dir/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/worldlib.dir/world.cpp.i"
	cd /testcode/HelloWorld/build/world && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /testcode/HelloWorld/world/world.cpp > CMakeFiles/worldlib.dir/world.cpp.i

world/CMakeFiles/worldlib.dir/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/worldlib.dir/world.cpp.s"
	cd /testcode/HelloWorld/build/world && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /testcode/HelloWorld/world/world.cpp -o CMakeFiles/worldlib.dir/world.cpp.s

# Object files for target worldlib
worldlib_OBJECTS = \
"CMakeFiles/worldlib.dir/world.cpp.o"

# External object files for target worldlib
worldlib_EXTERNAL_OBJECTS =

world/libworldlib.so: world/CMakeFiles/worldlib.dir/world.cpp.o
world/libworldlib.so: world/CMakeFiles/worldlib.dir/build.make
world/libworldlib.so: world/CMakeFiles/worldlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/testcode/HelloWorld/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libworldlib.so"
	cd /testcode/HelloWorld/build/world && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/worldlib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
world/CMakeFiles/worldlib.dir/build: world/libworldlib.so
.PHONY : world/CMakeFiles/worldlib.dir/build

world/CMakeFiles/worldlib.dir/clean:
	cd /testcode/HelloWorld/build/world && $(CMAKE_COMMAND) -P CMakeFiles/worldlib.dir/cmake_clean.cmake
.PHONY : world/CMakeFiles/worldlib.dir/clean

world/CMakeFiles/worldlib.dir/depend:
	cd /testcode/HelloWorld/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /testcode/HelloWorld /testcode/HelloWorld/world /testcode/HelloWorld/build /testcode/HelloWorld/build/world /testcode/HelloWorld/build/world/CMakeFiles/worldlib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : world/CMakeFiles/worldlib.dir/depend

