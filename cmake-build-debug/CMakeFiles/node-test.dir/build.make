# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "/Users/Pavel/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/Pavel/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Pavel/programs/Networks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Pavel/programs/Networks/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/node-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/node-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/node-test.dir/flags.make

CMakeFiles/node-test.dir/week7/node.c.o: CMakeFiles/node-test.dir/flags.make
CMakeFiles/node-test.dir/week7/node.c.o: ../week7/node.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Pavel/programs/Networks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/node-test.dir/week7/node.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/node-test.dir/week7/node.c.o   -c /Users/Pavel/programs/Networks/week7/node.c

CMakeFiles/node-test.dir/week7/node.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/node-test.dir/week7/node.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Pavel/programs/Networks/week7/node.c > CMakeFiles/node-test.dir/week7/node.c.i

CMakeFiles/node-test.dir/week7/node.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/node-test.dir/week7/node.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Pavel/programs/Networks/week7/node.c -o CMakeFiles/node-test.dir/week7/node.c.s

CMakeFiles/node-test.dir/dict/hashmap.c.o: CMakeFiles/node-test.dir/flags.make
CMakeFiles/node-test.dir/dict/hashmap.c.o: ../dict/hashmap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Pavel/programs/Networks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/node-test.dir/dict/hashmap.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/node-test.dir/dict/hashmap.c.o   -c /Users/Pavel/programs/Networks/dict/hashmap.c

CMakeFiles/node-test.dir/dict/hashmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/node-test.dir/dict/hashmap.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Pavel/programs/Networks/dict/hashmap.c > CMakeFiles/node-test.dir/dict/hashmap.c.i

CMakeFiles/node-test.dir/dict/hashmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/node-test.dir/dict/hashmap.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Pavel/programs/Networks/dict/hashmap.c -o CMakeFiles/node-test.dir/dict/hashmap.c.s

# Object files for target node-test
node__test_OBJECTS = \
"CMakeFiles/node-test.dir/week7/node.c.o" \
"CMakeFiles/node-test.dir/dict/hashmap.c.o"

# External object files for target node-test
node__test_EXTERNAL_OBJECTS =

node-test: CMakeFiles/node-test.dir/week7/node.c.o
node-test: CMakeFiles/node-test.dir/dict/hashmap.c.o
node-test: CMakeFiles/node-test.dir/build.make
node-test: CMakeFiles/node-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Pavel/programs/Networks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable node-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/node-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/node-test.dir/build: node-test

.PHONY : CMakeFiles/node-test.dir/build

CMakeFiles/node-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/node-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/node-test.dir/clean

CMakeFiles/node-test.dir/depend:
	cd /Users/Pavel/programs/Networks/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Pavel/programs/Networks /Users/Pavel/programs/Networks /Users/Pavel/programs/Networks/cmake-build-debug /Users/Pavel/programs/Networks/cmake-build-debug /Users/Pavel/programs/Networks/cmake-build-debug/CMakeFiles/node-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/node-test.dir/depend

