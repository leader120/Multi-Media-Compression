# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/alex/Library/Mobile Documents/com~apple~CloudDocs/EE669/EE669/Homework3/stdvq"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/alex/Library/Mobile Documents/com~apple~CloudDocs/EE669/EE669/Homework3/stdvq/build"

# Include any dependencies generated for this target.
include CMakeFiles/voronoi_fs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/voronoi_fs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/voronoi_fs.dir/flags.make

CMakeFiles/voronoi_fs.dir/voronoi_fs.c.o: CMakeFiles/voronoi_fs.dir/flags.make
CMakeFiles/voronoi_fs.dir/voronoi_fs.c.o: ../voronoi_fs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/alex/Library/Mobile Documents/com~apple~CloudDocs/EE669/EE669/Homework3/stdvq/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/voronoi_fs.dir/voronoi_fs.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/voronoi_fs.dir/voronoi_fs.c.o   -c "/Users/alex/Library/Mobile Documents/com~apple~CloudDocs/EE669/EE669/Homework3/stdvq/voronoi_fs.c"

CMakeFiles/voronoi_fs.dir/voronoi_fs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/voronoi_fs.dir/voronoi_fs.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/alex/Library/Mobile Documents/com~apple~CloudDocs/EE669/EE669/Homework3/stdvq/voronoi_fs.c" > CMakeFiles/voronoi_fs.dir/voronoi_fs.c.i

CMakeFiles/voronoi_fs.dir/voronoi_fs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/voronoi_fs.dir/voronoi_fs.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/alex/Library/Mobile Documents/com~apple~CloudDocs/EE669/EE669/Homework3/stdvq/voronoi_fs.c" -o CMakeFiles/voronoi_fs.dir/voronoi_fs.c.s

# Object files for target voronoi_fs
voronoi_fs_OBJECTS = \
"CMakeFiles/voronoi_fs.dir/voronoi_fs.c.o"

# External object files for target voronoi_fs
voronoi_fs_EXTERNAL_OBJECTS =

../voronoi_fs: CMakeFiles/voronoi_fs.dir/voronoi_fs.c.o
../voronoi_fs: CMakeFiles/voronoi_fs.dir/build.make
../voronoi_fs: ../lib/libHW3.dylib
../voronoi_fs: CMakeFiles/voronoi_fs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/alex/Library/Mobile Documents/com~apple~CloudDocs/EE669/EE669/Homework3/stdvq/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../voronoi_fs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/voronoi_fs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/voronoi_fs.dir/build: ../voronoi_fs

.PHONY : CMakeFiles/voronoi_fs.dir/build

CMakeFiles/voronoi_fs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/voronoi_fs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/voronoi_fs.dir/clean

CMakeFiles/voronoi_fs.dir/depend:
	cd "/Users/alex/Library/Mobile Documents/com~apple~CloudDocs/EE669/EE669/Homework3/stdvq/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/alex/Library/Mobile Documents/com~apple~CloudDocs/EE669/EE669/Homework3/stdvq" "/Users/alex/Library/Mobile Documents/com~apple~CloudDocs/EE669/EE669/Homework3/stdvq" "/Users/alex/Library/Mobile Documents/com~apple~CloudDocs/EE669/EE669/Homework3/stdvq/build" "/Users/alex/Library/Mobile Documents/com~apple~CloudDocs/EE669/EE669/Homework3/stdvq/build" "/Users/alex/Library/Mobile Documents/com~apple~CloudDocs/EE669/EE669/Homework3/stdvq/build/CMakeFiles/voronoi_fs.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/voronoi_fs.dir/depend

