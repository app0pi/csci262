# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\kenny\CLionProjects\Kattis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\kenny\CLionProjects\Kattis\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Kattis.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Kattis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Kattis.dir/flags.make

CMakeFiles/Kattis.dir/main.cpp.obj: CMakeFiles/Kattis.dir/flags.make
CMakeFiles/Kattis.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kenny\CLionProjects\Kattis\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Kattis.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Kattis.dir\main.cpp.obj -c C:\Users\kenny\CLionProjects\Kattis\main.cpp

CMakeFiles/Kattis.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kattis.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kenny\CLionProjects\Kattis\main.cpp > CMakeFiles\Kattis.dir\main.cpp.i

CMakeFiles/Kattis.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kattis.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kenny\CLionProjects\Kattis\main.cpp -o CMakeFiles\Kattis.dir\main.cpp.s

# Object files for target Kattis
Kattis_OBJECTS = \
"CMakeFiles/Kattis.dir/main.cpp.obj"

# External object files for target Kattis
Kattis_EXTERNAL_OBJECTS =

Kattis.exe: CMakeFiles/Kattis.dir/main.cpp.obj
Kattis.exe: CMakeFiles/Kattis.dir/build.make
Kattis.exe: CMakeFiles/Kattis.dir/linklibs.rsp
Kattis.exe: CMakeFiles/Kattis.dir/objects1.rsp
Kattis.exe: CMakeFiles/Kattis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\kenny\CLionProjects\Kattis\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Kattis.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Kattis.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Kattis.dir/build: Kattis.exe

.PHONY : CMakeFiles/Kattis.dir/build

CMakeFiles/Kattis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Kattis.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Kattis.dir/clean

CMakeFiles/Kattis.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\kenny\CLionProjects\Kattis C:\Users\kenny\CLionProjects\Kattis C:\Users\kenny\CLionProjects\Kattis\cmake-build-debug C:\Users\kenny\CLionProjects\Kattis\cmake-build-debug C:\Users\kenny\CLionProjects\Kattis\cmake-build-debug\CMakeFiles\Kattis.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Kattis.dir/depend
