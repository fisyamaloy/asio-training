# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/danil/Programming/asio-training

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/danil/Programming/asio-training/build

# Include any dependencies generated for this target.
include Network/CMakeFiles/Network.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Network/CMakeFiles/Network.dir/compiler_depend.make

# Include the progress variables for this target.
include Network/CMakeFiles/Network.dir/progress.make

# Include the compile flags for this target's objects.
include Network/CMakeFiles/Network.dir/flags.make

# Object files for target Network
Network_OBJECTS =

# External object files for target Network
Network_EXTERNAL_OBJECTS =

lib/libNetwork.a: Network/CMakeFiles/Network.dir/build.make
lib/libNetwork.a: Network/CMakeFiles/Network.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danil/Programming/asio-training/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library ../lib/libNetwork.a"
	cd /home/danil/Programming/asio-training/build/Network && $(CMAKE_COMMAND) -P CMakeFiles/Network.dir/cmake_clean_target.cmake
	cd /home/danil/Programming/asio-training/build/Network && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Network.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Network/CMakeFiles/Network.dir/build: lib/libNetwork.a
.PHONY : Network/CMakeFiles/Network.dir/build

Network/CMakeFiles/Network.dir/clean:
	cd /home/danil/Programming/asio-training/build/Network && $(CMAKE_COMMAND) -P CMakeFiles/Network.dir/cmake_clean.cmake
.PHONY : Network/CMakeFiles/Network.dir/clean

Network/CMakeFiles/Network.dir/depend:
	cd /home/danil/Programming/asio-training/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danil/Programming/asio-training /home/danil/Programming/asio-training/Network /home/danil/Programming/asio-training/build /home/danil/Programming/asio-training/build/Network /home/danil/Programming/asio-training/build/Network/CMakeFiles/Network.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Network/CMakeFiles/Network.dir/depend

