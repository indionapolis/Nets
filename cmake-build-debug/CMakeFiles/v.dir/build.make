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
include CMakeFiles/v.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/v.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/v.dir/flags.make

CMakeFiles/v.dir/dict/main.c.o: CMakeFiles/v.dir/flags.make
CMakeFiles/v.dir/dict/main.c.o: ../dict/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Pavel/programs/Networks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/v.dir/dict/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/v.dir/dict/main.c.o   -c /Users/Pavel/programs/Networks/dict/main.c

CMakeFiles/v.dir/dict/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/v.dir/dict/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Pavel/programs/Networks/dict/main.c > CMakeFiles/v.dir/dict/main.c.i

CMakeFiles/v.dir/dict/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/v.dir/dict/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Pavel/programs/Networks/dict/main.c -o CMakeFiles/v.dir/dict/main.c.s

CMakeFiles/v.dir/dict/hashmap.c.o: CMakeFiles/v.dir/flags.make
CMakeFiles/v.dir/dict/hashmap.c.o: ../dict/hashmap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Pavel/programs/Networks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/v.dir/dict/hashmap.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/v.dir/dict/hashmap.c.o   -c /Users/Pavel/programs/Networks/dict/hashmap.c

CMakeFiles/v.dir/dict/hashmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/v.dir/dict/hashmap.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Pavel/programs/Networks/dict/hashmap.c > CMakeFiles/v.dir/dict/hashmap.c.i

CMakeFiles/v.dir/dict/hashmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/v.dir/dict/hashmap.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Pavel/programs/Networks/dict/hashmap.c -o CMakeFiles/v.dir/dict/hashmap.c.s

# Object files for target v
v_OBJECTS = \
"CMakeFiles/v.dir/dict/main.c.o" \
"CMakeFiles/v.dir/dict/hashmap.c.o"

# External object files for target v
v_EXTERNAL_OBJECTS =

v : CMakeFiles/v.dir/dict/main.c.o
v : CMakeFiles/v.dir/dict/hashmap.c.o
v : CMakeFiles/v.dir/build.make
v : CMakeFiles/v.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Pavel/programs/Networks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable v"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/v.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/v.dir/build: v

.PHONY : CMakeFiles/v.dir/build

CMakeFiles/v.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/v.dir/cmake_clean.cmake
.PHONY : CMakeFiles/v.dir/clean

CMakeFiles/v.dir/depend:
	cd /Users/Pavel/programs/Networks/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Pavel/programs/Networks /Users/Pavel/programs/Networks /Users/Pavel/programs/Networks/cmake-build-debug /Users/Pavel/programs/Networks/cmake-build-debug /Users/Pavel/programs/Networks/cmake-build-debug/CMakeFiles/v.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/v.dir/depend

