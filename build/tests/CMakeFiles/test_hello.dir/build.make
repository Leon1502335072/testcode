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
CMAKE_BINARY_DIR = /testcode/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_hello.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/test_hello.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_hello.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_hello.dir/flags.make

tests/CMakeFiles/test_hello.dir/test_hello.cpp.o: tests/CMakeFiles/test_hello.dir/flags.make
tests/CMakeFiles/test_hello.dir/test_hello.cpp.o: /testcode/HelloWorld/tests/test_hello.cpp
tests/CMakeFiles/test_hello.dir/test_hello.cpp.o: tests/CMakeFiles/test_hello.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/testcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_hello.dir/test_hello.cpp.o"
	cd /testcode/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/test_hello.dir/test_hello.cpp.o -MF CMakeFiles/test_hello.dir/test_hello.cpp.o.d -o CMakeFiles/test_hello.dir/test_hello.cpp.o -c /testcode/HelloWorld/tests/test_hello.cpp

tests/CMakeFiles/test_hello.dir/test_hello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_hello.dir/test_hello.cpp.i"
	cd /testcode/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /testcode/HelloWorld/tests/test_hello.cpp > CMakeFiles/test_hello.dir/test_hello.cpp.i

tests/CMakeFiles/test_hello.dir/test_hello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_hello.dir/test_hello.cpp.s"
	cd /testcode/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /testcode/HelloWorld/tests/test_hello.cpp -o CMakeFiles/test_hello.dir/test_hello.cpp.s

# Object files for target test_hello
test_hello_OBJECTS = \
"CMakeFiles/test_hello.dir/test_hello.cpp.o"

# External object files for target test_hello
test_hello_EXTERNAL_OBJECTS =

tests/test_hello: tests/CMakeFiles/test_hello.dir/test_hello.cpp.o
tests/test_hello: tests/CMakeFiles/test_hello.dir/build.make
tests/test_hello: hello/libhellolib.so
tests/test_hello: lib/libgtest.a
tests/test_hello: lib/libgtest_main.a
tests/test_hello: lib/libgtest.a
tests/test_hello: tests/CMakeFiles/test_hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/testcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_hello"
	cd /testcode/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_hello.dir/build: tests/test_hello
.PHONY : tests/CMakeFiles/test_hello.dir/build

tests/CMakeFiles/test_hello.dir/clean:
	cd /testcode/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_hello.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_hello.dir/clean

tests/CMakeFiles/test_hello.dir/depend:
	cd /testcode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /testcode/HelloWorld /testcode/HelloWorld/tests /testcode/build /testcode/build/tests /testcode/build/tests/CMakeFiles/test_hello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test_hello.dir/depend

