# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "F:\Pepe\3rd semester\DS\Cpepe\Semester Project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "F:\Pepe\3rd semester\DS\Cpepe\Semester Project\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Semester_Project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Semester_Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Semester_Project.dir/flags.make

CMakeFiles/Semester_Project.dir/main.cpp.obj: CMakeFiles/Semester_Project.dir/flags.make
CMakeFiles/Semester_Project.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\Pepe\3rd semester\DS\Cpepe\Semester Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Semester_Project.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Semester_Project.dir\main.cpp.obj -c "F:\Pepe\3rd semester\DS\Cpepe\Semester Project\main.cpp"

CMakeFiles/Semester_Project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Semester_Project.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\Pepe\3rd semester\DS\Cpepe\Semester Project\main.cpp" > CMakeFiles\Semester_Project.dir\main.cpp.i

CMakeFiles/Semester_Project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Semester_Project.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "F:\Pepe\3rd semester\DS\Cpepe\Semester Project\main.cpp" -o CMakeFiles\Semester_Project.dir\main.cpp.s

# Object files for target Semester_Project
Semester_Project_OBJECTS = \
"CMakeFiles/Semester_Project.dir/main.cpp.obj"

# External object files for target Semester_Project
Semester_Project_EXTERNAL_OBJECTS =

Semester_Project.exe: CMakeFiles/Semester_Project.dir/main.cpp.obj
Semester_Project.exe: CMakeFiles/Semester_Project.dir/build.make
Semester_Project.exe: CMakeFiles/Semester_Project.dir/linklibs.rsp
Semester_Project.exe: CMakeFiles/Semester_Project.dir/objects1.rsp
Semester_Project.exe: CMakeFiles/Semester_Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\Pepe\3rd semester\DS\Cpepe\Semester Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Semester_Project.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Semester_Project.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Semester_Project.dir/build: Semester_Project.exe

.PHONY : CMakeFiles/Semester_Project.dir/build

CMakeFiles/Semester_Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Semester_Project.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Semester_Project.dir/clean

CMakeFiles/Semester_Project.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "F:\Pepe\3rd semester\DS\Cpepe\Semester Project" "F:\Pepe\3rd semester\DS\Cpepe\Semester Project" "F:\Pepe\3rd semester\DS\Cpepe\Semester Project\cmake-build-debug" "F:\Pepe\3rd semester\DS\Cpepe\Semester Project\cmake-build-debug" "F:\Pepe\3rd semester\DS\Cpepe\Semester Project\cmake-build-debug\CMakeFiles\Semester_Project.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Semester_Project.dir/depend
