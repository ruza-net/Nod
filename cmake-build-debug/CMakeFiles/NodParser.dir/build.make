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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/honzatemp/CLionProjects/NodParser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/honzatemp/CLionProjects/NodParser/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NodParser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NodParser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NodParser.dir/flags.make

CMakeFiles/NodParser.dir/main.cpp.o: CMakeFiles/NodParser.dir/flags.make
CMakeFiles/NodParser.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/honzatemp/CLionProjects/NodParser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NodParser.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NodParser.dir/main.cpp.o -c /Users/honzatemp/CLionProjects/NodParser/main.cpp

CMakeFiles/NodParser.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NodParser.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/honzatemp/CLionProjects/NodParser/main.cpp > CMakeFiles/NodParser.dir/main.cpp.i

CMakeFiles/NodParser.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NodParser.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/honzatemp/CLionProjects/NodParser/main.cpp -o CMakeFiles/NodParser.dir/main.cpp.s

CMakeFiles/NodParser.dir/parse/Lexer.cpp.o: CMakeFiles/NodParser.dir/flags.make
CMakeFiles/NodParser.dir/parse/Lexer.cpp.o: ../parse/Lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/honzatemp/CLionProjects/NodParser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NodParser.dir/parse/Lexer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NodParser.dir/parse/Lexer.cpp.o -c /Users/honzatemp/CLionProjects/NodParser/parse/Lexer.cpp

CMakeFiles/NodParser.dir/parse/Lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NodParser.dir/parse/Lexer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/honzatemp/CLionProjects/NodParser/parse/Lexer.cpp > CMakeFiles/NodParser.dir/parse/Lexer.cpp.i

CMakeFiles/NodParser.dir/parse/Lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NodParser.dir/parse/Lexer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/honzatemp/CLionProjects/NodParser/parse/Lexer.cpp -o CMakeFiles/NodParser.dir/parse/Lexer.cpp.s

# Object files for target NodParser
NodParser_OBJECTS = \
"CMakeFiles/NodParser.dir/main.cpp.o" \
"CMakeFiles/NodParser.dir/parse/Lexer.cpp.o"

# External object files for target NodParser
NodParser_EXTERNAL_OBJECTS =

NodParser: CMakeFiles/NodParser.dir/main.cpp.o
NodParser: CMakeFiles/NodParser.dir/parse/Lexer.cpp.o
NodParser: CMakeFiles/NodParser.dir/build.make
NodParser: CMakeFiles/NodParser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/honzatemp/CLionProjects/NodParser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable NodParser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NodParser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NodParser.dir/build: NodParser

.PHONY : CMakeFiles/NodParser.dir/build

CMakeFiles/NodParser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NodParser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NodParser.dir/clean

CMakeFiles/NodParser.dir/depend:
	cd /Users/honzatemp/CLionProjects/NodParser/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/honzatemp/CLionProjects/NodParser /Users/honzatemp/CLionProjects/NodParser /Users/honzatemp/CLionProjects/NodParser/cmake-build-debug /Users/honzatemp/CLionProjects/NodParser/cmake-build-debug /Users/honzatemp/CLionProjects/NodParser/cmake-build-debug/CMakeFiles/NodParser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NodParser.dir/depend
