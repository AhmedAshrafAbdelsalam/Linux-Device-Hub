# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/ahmedashraf/Training/Hub

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ahmedashraf/Training/Hub/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/EXAMPLE.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/EXAMPLE.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/EXAMPLE.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/EXAMPLE.dir/flags.make

examples/CMakeFiles/EXAMPLE.dir/main.cpp.o: examples/CMakeFiles/EXAMPLE.dir/flags.make
examples/CMakeFiles/EXAMPLE.dir/main.cpp.o: /home/ahmedashraf/Training/Hub/examples/main.cpp
examples/CMakeFiles/EXAMPLE.dir/main.cpp.o: examples/CMakeFiles/EXAMPLE.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmedashraf/Training/Hub/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/EXAMPLE.dir/main.cpp.o"
	cd /home/ahmedashraf/Training/Hub/build/examples && /usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/CMakeFiles/EXAMPLE.dir/main.cpp.o -MF CMakeFiles/EXAMPLE.dir/main.cpp.o.d -o CMakeFiles/EXAMPLE.dir/main.cpp.o -c /home/ahmedashraf/Training/Hub/examples/main.cpp

examples/CMakeFiles/EXAMPLE.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EXAMPLE.dir/main.cpp.i"
	cd /home/ahmedashraf/Training/Hub/build/examples && /usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmedashraf/Training/Hub/examples/main.cpp > CMakeFiles/EXAMPLE.dir/main.cpp.i

examples/CMakeFiles/EXAMPLE.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EXAMPLE.dir/main.cpp.s"
	cd /home/ahmedashraf/Training/Hub/build/examples && /usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmedashraf/Training/Hub/examples/main.cpp -o CMakeFiles/EXAMPLE.dir/main.cpp.s

# Object files for target EXAMPLE
EXAMPLE_OBJECTS = \
"CMakeFiles/EXAMPLE.dir/main.cpp.o"

# External object files for target EXAMPLE
EXAMPLE_EXTERNAL_OBJECTS =

examples/EXAMPLE: examples/CMakeFiles/EXAMPLE.dir/main.cpp.o
examples/EXAMPLE: examples/CMakeFiles/EXAMPLE.dir/build.make
examples/EXAMPLE: src/libLINUX_DEVICE_HUB.a
examples/EXAMPLE: examples/CMakeFiles/EXAMPLE.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmedashraf/Training/Hub/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable EXAMPLE"
	cd /home/ahmedashraf/Training/Hub/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EXAMPLE.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/EXAMPLE.dir/build: examples/EXAMPLE
.PHONY : examples/CMakeFiles/EXAMPLE.dir/build

examples/CMakeFiles/EXAMPLE.dir/clean:
	cd /home/ahmedashraf/Training/Hub/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/EXAMPLE.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/EXAMPLE.dir/clean

examples/CMakeFiles/EXAMPLE.dir/depend:
	cd /home/ahmedashraf/Training/Hub/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmedashraf/Training/Hub /home/ahmedashraf/Training/Hub/examples /home/ahmedashraf/Training/Hub/build /home/ahmedashraf/Training/Hub/build/examples /home/ahmedashraf/Training/Hub/build/examples/CMakeFiles/EXAMPLE.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/EXAMPLE.dir/depend

