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
include Test/CMakeFiles/Test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Test/CMakeFiles/Test.dir/compiler_depend.make

# Include the progress variables for this target.
include Test/CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include Test/CMakeFiles/Test.dir/flags.make

Test/CMakeFiles/Test.dir/MainTest.cpp.o: Test/CMakeFiles/Test.dir/flags.make
Test/CMakeFiles/Test.dir/MainTest.cpp.o: ../Test/MainTest.cpp
Test/CMakeFiles/Test.dir/MainTest.cpp.o: Test/CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danil/Programming/asio-training/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Test/CMakeFiles/Test.dir/MainTest.cpp.o"
	cd /home/danil/Programming/asio-training/build/Test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Test/CMakeFiles/Test.dir/MainTest.cpp.o -MF CMakeFiles/Test.dir/MainTest.cpp.o.d -o CMakeFiles/Test.dir/MainTest.cpp.o -c /home/danil/Programming/asio-training/Test/MainTest.cpp

Test/CMakeFiles/Test.dir/MainTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/MainTest.cpp.i"
	cd /home/danil/Programming/asio-training/build/Test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danil/Programming/asio-training/Test/MainTest.cpp > CMakeFiles/Test.dir/MainTest.cpp.i

Test/CMakeFiles/Test.dir/MainTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/MainTest.cpp.s"
	cd /home/danil/Programming/asio-training/build/Test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danil/Programming/asio-training/Test/MainTest.cpp -o CMakeFiles/Test.dir/MainTest.cpp.s

# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/MainTest.cpp.o"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

bin/Test: Test/CMakeFiles/Test.dir/MainTest.cpp.o
bin/Test: Test/CMakeFiles/Test.dir/build.make
bin/Test: lib/libNetwork.a
bin/Test: /home/danil/.conan/data/gtest/1.10.0/_/_/package/63868df56b76903d4ad40ecbd5b2e8238cee50c9/lib/libgtest_maind.a
bin/Test: /home/danil/.conan/data/gtest/1.10.0/_/_/package/63868df56b76903d4ad40ecbd5b2e8238cee50c9/lib/libgmock_maind.a
bin/Test: /home/danil/.conan/data/gtest/1.10.0/_/_/package/63868df56b76903d4ad40ecbd5b2e8238cee50c9/lib/libgmockd.a
bin/Test: /home/danil/.conan/data/gtest/1.10.0/_/_/package/63868df56b76903d4ad40ecbd5b2e8238cee50c9/lib/libgtestd.a
bin/Test: Test/CMakeFiles/Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danil/Programming/asio-training/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/Test"
	cd /home/danil/Programming/asio-training/build/Test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Test/CMakeFiles/Test.dir/build: bin/Test
.PHONY : Test/CMakeFiles/Test.dir/build

Test/CMakeFiles/Test.dir/clean:
	cd /home/danil/Programming/asio-training/build/Test && $(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean.cmake
.PHONY : Test/CMakeFiles/Test.dir/clean

Test/CMakeFiles/Test.dir/depend:
	cd /home/danil/Programming/asio-training/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danil/Programming/asio-training /home/danil/Programming/asio-training/Test /home/danil/Programming/asio-training/build /home/danil/Programming/asio-training/build/Test /home/danil/Programming/asio-training/build/Test/CMakeFiles/Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Test/CMakeFiles/Test.dir/depend

