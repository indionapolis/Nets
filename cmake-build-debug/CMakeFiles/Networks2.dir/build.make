# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "/Users/Pavel/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4892.24/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/Pavel/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4892.24/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Pavel/programs/Networks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Pavel/programs/Networks/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Networks2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Networks2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Networks2.dir/flags.make

CMakeFiles/Networks2.dir/week4/client.c.o: CMakeFiles/Networks2.dir/flags.make
CMakeFiles/Networks2.dir/week4/client.c.o: ../week4/client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Pavel/programs/Networks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Networks2.dir/week4/client.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Networks2.dir/week4/client.c.o   -c /Users/Pavel/programs/Networks/week4/client.c

CMakeFiles/Networks2.dir/week4/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Networks2.dir/week4/client.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Pavel/programs/Networks/week4/client.c > CMakeFiles/Networks2.dir/week4/client.c.i

CMakeFiles/Networks2.dir/week4/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Networks2.dir/week4/client.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Pavel/programs/Networks/week4/client.c -o CMakeFiles/Networks2.dir/week4/client.c.s

# Object files for target Networks2
Networks2_OBJECTS = \
"CMakeFiles/Networks2.dir/week4/client.c.o"

# External object files for target Networks2
Networks2_EXTERNAL_OBJECTS =

Networks2: CMakeFiles/Networks2.dir/week4/client.c.o
Networks2: CMakeFiles/Networks2.dir/build.make
Networks2: CMakeFiles/Networks2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Pavel/programs/Networks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Networks2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Networks2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Networks2.dir/build: Networks2

.PHONY : CMakeFiles/Networks2.dir/build

CMakeFiles/Networks2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Networks2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Networks2.dir/clean

CMakeFiles/Networks2.dir/depend:
	cd /Users/Pavel/programs/Networks/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Pavel/programs/Networks /Users/Pavel/programs/Networks /Users/Pavel/programs/Networks/cmake-build-debug /Users/Pavel/programs/Networks/cmake-build-debug /Users/Pavel/programs/Networks/cmake-build-debug/CMakeFiles/Networks2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Networks2.dir/depend
