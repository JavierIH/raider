# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/javierih/raider/Raider/programming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/javierih/raider/Raider/programming/build

# Include any dependencies generated for this target.
include src/libraries/bones/CMakeFiles/bones.dir/depend.make

# Include the progress variables for this target.
include src/libraries/bones/CMakeFiles/bones.dir/progress.make

# Include the compile flags for this target's objects.
include src/libraries/bones/CMakeFiles/bones.dir/flags.make

src/libraries/bones/CMakeFiles/bones.dir/bones.cpp.o: src/libraries/bones/CMakeFiles/bones.dir/flags.make
src/libraries/bones/CMakeFiles/bones.dir/bones.cpp.o: ../src/libraries/bones/bones.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/javierih/raider/Raider/programming/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/libraries/bones/CMakeFiles/bones.dir/bones.cpp.o"
	cd /home/javierih/raider/Raider/programming/build/src/libraries/bones && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/bones.dir/bones.cpp.o -c /home/javierih/raider/Raider/programming/src/libraries/bones/bones.cpp

src/libraries/bones/CMakeFiles/bones.dir/bones.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bones.dir/bones.cpp.i"
	cd /home/javierih/raider/Raider/programming/build/src/libraries/bones && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/javierih/raider/Raider/programming/src/libraries/bones/bones.cpp > CMakeFiles/bones.dir/bones.cpp.i

src/libraries/bones/CMakeFiles/bones.dir/bones.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bones.dir/bones.cpp.s"
	cd /home/javierih/raider/Raider/programming/build/src/libraries/bones && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/javierih/raider/Raider/programming/src/libraries/bones/bones.cpp -o CMakeFiles/bones.dir/bones.cpp.s

src/libraries/bones/CMakeFiles/bones.dir/bones.cpp.o.requires:
.PHONY : src/libraries/bones/CMakeFiles/bones.dir/bones.cpp.o.requires

src/libraries/bones/CMakeFiles/bones.dir/bones.cpp.o.provides: src/libraries/bones/CMakeFiles/bones.dir/bones.cpp.o.requires
	$(MAKE) -f src/libraries/bones/CMakeFiles/bones.dir/build.make src/libraries/bones/CMakeFiles/bones.dir/bones.cpp.o.provides.build
.PHONY : src/libraries/bones/CMakeFiles/bones.dir/bones.cpp.o.provides

src/libraries/bones/CMakeFiles/bones.dir/bones.cpp.o.provides.build: src/libraries/bones/CMakeFiles/bones.dir/bones.cpp.o

# Object files for target bones
bones_OBJECTS = \
"CMakeFiles/bones.dir/bones.cpp.o"

# External object files for target bones
bones_EXTERNAL_OBJECTS =

lib/libbones.so: src/libraries/bones/CMakeFiles/bones.dir/bones.cpp.o
lib/libbones.so: src/libraries/bones/CMakeFiles/bones.dir/build.make
lib/libbones.so: lib/libserialib.so
lib/libbones.so: src/libraries/bones/CMakeFiles/bones.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../../lib/libbones.so"
	cd /home/javierih/raider/Raider/programming/build/src/libraries/bones && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bones.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/libraries/bones/CMakeFiles/bones.dir/build: lib/libbones.so
.PHONY : src/libraries/bones/CMakeFiles/bones.dir/build

src/libraries/bones/CMakeFiles/bones.dir/requires: src/libraries/bones/CMakeFiles/bones.dir/bones.cpp.o.requires
.PHONY : src/libraries/bones/CMakeFiles/bones.dir/requires

src/libraries/bones/CMakeFiles/bones.dir/clean:
	cd /home/javierih/raider/Raider/programming/build/src/libraries/bones && $(CMAKE_COMMAND) -P CMakeFiles/bones.dir/cmake_clean.cmake
.PHONY : src/libraries/bones/CMakeFiles/bones.dir/clean

src/libraries/bones/CMakeFiles/bones.dir/depend:
	cd /home/javierih/raider/Raider/programming/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javierih/raider/Raider/programming /home/javierih/raider/Raider/programming/src/libraries/bones /home/javierih/raider/Raider/programming/build /home/javierih/raider/Raider/programming/build/src/libraries/bones /home/javierih/raider/Raider/programming/build/src/libraries/bones/CMakeFiles/bones.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/libraries/bones/CMakeFiles/bones.dir/depend
