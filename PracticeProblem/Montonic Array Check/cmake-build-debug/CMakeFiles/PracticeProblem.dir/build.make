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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/shanthosh/Documents/SYDE223/PracticeProblem/Montonic Array Check"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/shanthosh/Documents/SYDE223/PracticeProblem/Montonic Array Check/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/PracticeProblem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PracticeProblem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PracticeProblem.dir/flags.make

CMakeFiles/PracticeProblem.dir/main.cpp.o: CMakeFiles/PracticeProblem.dir/flags.make
CMakeFiles/PracticeProblem.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shanthosh/Documents/SYDE223/PracticeProblem/Montonic Array Check/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PracticeProblem.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PracticeProblem.dir/main.cpp.o -c "/Users/shanthosh/Documents/SYDE223/PracticeProblem/Montonic Array Check/main.cpp"

CMakeFiles/PracticeProblem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PracticeProblem.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shanthosh/Documents/SYDE223/PracticeProblem/Montonic Array Check/main.cpp" > CMakeFiles/PracticeProblem.dir/main.cpp.i

CMakeFiles/PracticeProblem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PracticeProblem.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shanthosh/Documents/SYDE223/PracticeProblem/Montonic Array Check/main.cpp" -o CMakeFiles/PracticeProblem.dir/main.cpp.s

# Object files for target PracticeProblem
PracticeProblem_OBJECTS = \
"CMakeFiles/PracticeProblem.dir/main.cpp.o"

# External object files for target PracticeProblem
PracticeProblem_EXTERNAL_OBJECTS =

PracticeProblem: CMakeFiles/PracticeProblem.dir/main.cpp.o
PracticeProblem: CMakeFiles/PracticeProblem.dir/build.make
PracticeProblem: CMakeFiles/PracticeProblem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/shanthosh/Documents/SYDE223/PracticeProblem/Montonic Array Check/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PracticeProblem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PracticeProblem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PracticeProblem.dir/build: PracticeProblem

.PHONY : CMakeFiles/PracticeProblem.dir/build

CMakeFiles/PracticeProblem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PracticeProblem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PracticeProblem.dir/clean

CMakeFiles/PracticeProblem.dir/depend:
	cd "/Users/shanthosh/Documents/SYDE223/PracticeProblem/Montonic Array Check/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/shanthosh/Documents/SYDE223/PracticeProblem/Montonic Array Check" "/Users/shanthosh/Documents/SYDE223/PracticeProblem/Montonic Array Check" "/Users/shanthosh/Documents/SYDE223/PracticeProblem/Montonic Array Check/cmake-build-debug" "/Users/shanthosh/Documents/SYDE223/PracticeProblem/Montonic Array Check/cmake-build-debug" "/Users/shanthosh/Documents/SYDE223/PracticeProblem/Montonic Array Check/cmake-build-debug/CMakeFiles/PracticeProblem.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/PracticeProblem.dir/depend

