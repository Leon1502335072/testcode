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
CMAKE_SOURCE_DIR = /testcode/Designpattern

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /testcode/Designpattern/build

# Include any dependencies generated for this target.
include CMakeFiles/318Mediator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/318Mediator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/318Mediator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/318Mediator.dir/flags.make

CMakeFiles/318Mediator.dir/318Mediator.cpp.o: CMakeFiles/318Mediator.dir/flags.make
CMakeFiles/318Mediator.dir/318Mediator.cpp.o: ../318Mediator.cpp
CMakeFiles/318Mediator.dir/318Mediator.cpp.o: CMakeFiles/318Mediator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/testcode/Designpattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/318Mediator.dir/318Mediator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/318Mediator.dir/318Mediator.cpp.o -MF CMakeFiles/318Mediator.dir/318Mediator.cpp.o.d -o CMakeFiles/318Mediator.dir/318Mediator.cpp.o -c /testcode/Designpattern/318Mediator.cpp

CMakeFiles/318Mediator.dir/318Mediator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/318Mediator.dir/318Mediator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /testcode/Designpattern/318Mediator.cpp > CMakeFiles/318Mediator.dir/318Mediator.cpp.i

CMakeFiles/318Mediator.dir/318Mediator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/318Mediator.dir/318Mediator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /testcode/Designpattern/318Mediator.cpp -o CMakeFiles/318Mediator.dir/318Mediator.cpp.s

# Object files for target 318Mediator
318Mediator_OBJECTS = \
"CMakeFiles/318Mediator.dir/318Mediator.cpp.o"

# External object files for target 318Mediator
318Mediator_EXTERNAL_OBJECTS =

/testcode/bin/318Mediator: CMakeFiles/318Mediator.dir/318Mediator.cpp.o
/testcode/bin/318Mediator: CMakeFiles/318Mediator.dir/build.make
/testcode/bin/318Mediator: CMakeFiles/318Mediator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/testcode/Designpattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /testcode/bin/318Mediator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/318Mediator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/318Mediator.dir/build: /testcode/bin/318Mediator
.PHONY : CMakeFiles/318Mediator.dir/build

CMakeFiles/318Mediator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/318Mediator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/318Mediator.dir/clean

CMakeFiles/318Mediator.dir/depend:
	cd /testcode/Designpattern/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /testcode/Designpattern /testcode/Designpattern /testcode/Designpattern/build /testcode/Designpattern/build /testcode/Designpattern/build/CMakeFiles/318Mediator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/318Mediator.dir/depend

