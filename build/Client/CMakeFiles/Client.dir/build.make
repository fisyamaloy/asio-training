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
include Client/CMakeFiles/Client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Client/CMakeFiles/Client.dir/compiler_depend.make

# Include the progress variables for this target.
include Client/CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include Client/CMakeFiles/Client.dir/flags.make

Client/CMakeFiles/Client.dir/MainClient.cpp.o: Client/CMakeFiles/Client.dir/flags.make
Client/CMakeFiles/Client.dir/MainClient.cpp.o: ../Client/MainClient.cpp
Client/CMakeFiles/Client.dir/MainClient.cpp.o: Client/CMakeFiles/Client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danil/Programming/asio-training/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Client/CMakeFiles/Client.dir/MainClient.cpp.o"
	cd /home/danil/Programming/asio-training/build/Client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Client/CMakeFiles/Client.dir/MainClient.cpp.o -MF CMakeFiles/Client.dir/MainClient.cpp.o.d -o CMakeFiles/Client.dir/MainClient.cpp.o -c /home/danil/Programming/asio-training/Client/MainClient.cpp

Client/CMakeFiles/Client.dir/MainClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/MainClient.cpp.i"
	cd /home/danil/Programming/asio-training/build/Client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danil/Programming/asio-training/Client/MainClient.cpp > CMakeFiles/Client.dir/MainClient.cpp.i

Client/CMakeFiles/Client.dir/MainClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/MainClient.cpp.s"
	cd /home/danil/Programming/asio-training/build/Client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danil/Programming/asio-training/Client/MainClient.cpp -o CMakeFiles/Client.dir/MainClient.cpp.s

# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/MainClient.cpp.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

bin/Client: Client/CMakeFiles/Client.dir/MainClient.cpp.o
bin/Client: Client/CMakeFiles/Client.dir/build.make
bin/Client: Client/CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danil/Programming/asio-training/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/Client"
	cd /home/danil/Programming/asio-training/build/Client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Client/CMakeFiles/Client.dir/build: bin/Client
.PHONY : Client/CMakeFiles/Client.dir/build

Client/CMakeFiles/Client.dir/clean:
	cd /home/danil/Programming/asio-training/build/Client && $(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : Client/CMakeFiles/Client.dir/clean

Client/CMakeFiles/Client.dir/depend:
	cd /home/danil/Programming/asio-training/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danil/Programming/asio-training /home/danil/Programming/asio-training/Client /home/danil/Programming/asio-training/build /home/danil/Programming/asio-training/build/Client /home/danil/Programming/asio-training/build/Client/CMakeFiles/Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Client/CMakeFiles/Client.dir/depend

