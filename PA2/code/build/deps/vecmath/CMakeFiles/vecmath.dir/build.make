# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/e/重要文件/大二下/图形学/PA2_New/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/e/重要文件/大二下/图形学/PA2_New/code/build

# Include any dependencies generated for this target.
include deps/vecmath/CMakeFiles/vecmath.dir/depend.make

# Include the progress variables for this target.
include deps/vecmath/CMakeFiles/vecmath.dir/progress.make

# Include the compile flags for this target's objects.
include deps/vecmath/CMakeFiles/vecmath.dir/flags.make

deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o: deps/vecmath/CMakeFiles/vecmath.dir/flags.make
deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o: ../deps/vecmath/src/Matrix2f.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/重要文件/大二下/图形学/PA2_New/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o -c /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Matrix2f.cpp

deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vecmath.dir/src/Matrix2f.cpp.i"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Matrix2f.cpp > CMakeFiles/vecmath.dir/src/Matrix2f.cpp.i

deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vecmath.dir/src/Matrix2f.cpp.s"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Matrix2f.cpp -o CMakeFiles/vecmath.dir/src/Matrix2f.cpp.s

deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o: deps/vecmath/CMakeFiles/vecmath.dir/flags.make
deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o: ../deps/vecmath/src/Matrix3f.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/重要文件/大二下/图形学/PA2_New/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o -c /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Matrix3f.cpp

deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vecmath.dir/src/Matrix3f.cpp.i"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Matrix3f.cpp > CMakeFiles/vecmath.dir/src/Matrix3f.cpp.i

deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vecmath.dir/src/Matrix3f.cpp.s"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Matrix3f.cpp -o CMakeFiles/vecmath.dir/src/Matrix3f.cpp.s

deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o: deps/vecmath/CMakeFiles/vecmath.dir/flags.make
deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o: ../deps/vecmath/src/Matrix4f.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/重要文件/大二下/图形学/PA2_New/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o -c /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Matrix4f.cpp

deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vecmath.dir/src/Matrix4f.cpp.i"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Matrix4f.cpp > CMakeFiles/vecmath.dir/src/Matrix4f.cpp.i

deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vecmath.dir/src/Matrix4f.cpp.s"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Matrix4f.cpp -o CMakeFiles/vecmath.dir/src/Matrix4f.cpp.s

deps/vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o: deps/vecmath/CMakeFiles/vecmath.dir/flags.make
deps/vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o: ../deps/vecmath/src/Quat4f.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/重要文件/大二下/图形学/PA2_New/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object deps/vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vecmath.dir/src/Quat4f.cpp.o -c /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Quat4f.cpp

deps/vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vecmath.dir/src/Quat4f.cpp.i"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Quat4f.cpp > CMakeFiles/vecmath.dir/src/Quat4f.cpp.i

deps/vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vecmath.dir/src/Quat4f.cpp.s"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Quat4f.cpp -o CMakeFiles/vecmath.dir/src/Quat4f.cpp.s

deps/vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o: deps/vecmath/CMakeFiles/vecmath.dir/flags.make
deps/vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o: ../deps/vecmath/src/Vector2f.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/重要文件/大二下/图形学/PA2_New/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object deps/vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vecmath.dir/src/Vector2f.cpp.o -c /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Vector2f.cpp

deps/vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vecmath.dir/src/Vector2f.cpp.i"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Vector2f.cpp > CMakeFiles/vecmath.dir/src/Vector2f.cpp.i

deps/vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vecmath.dir/src/Vector2f.cpp.s"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Vector2f.cpp -o CMakeFiles/vecmath.dir/src/Vector2f.cpp.s

deps/vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o: deps/vecmath/CMakeFiles/vecmath.dir/flags.make
deps/vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o: ../deps/vecmath/src/Vector3f.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/重要文件/大二下/图形学/PA2_New/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object deps/vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vecmath.dir/src/Vector3f.cpp.o -c /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Vector3f.cpp

deps/vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vecmath.dir/src/Vector3f.cpp.i"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Vector3f.cpp > CMakeFiles/vecmath.dir/src/Vector3f.cpp.i

deps/vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vecmath.dir/src/Vector3f.cpp.s"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Vector3f.cpp -o CMakeFiles/vecmath.dir/src/Vector3f.cpp.s

deps/vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o: deps/vecmath/CMakeFiles/vecmath.dir/flags.make
deps/vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o: ../deps/vecmath/src/Vector4f.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/重要文件/大二下/图形学/PA2_New/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object deps/vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vecmath.dir/src/Vector4f.cpp.o -c /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Vector4f.cpp

deps/vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vecmath.dir/src/Vector4f.cpp.i"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Vector4f.cpp > CMakeFiles/vecmath.dir/src/Vector4f.cpp.i

deps/vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vecmath.dir/src/Vector4f.cpp.s"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/Vector4f.cpp -o CMakeFiles/vecmath.dir/src/Vector4f.cpp.s

deps/vecmath/CMakeFiles/vecmath.dir/src/vecio.cpp.o: deps/vecmath/CMakeFiles/vecmath.dir/flags.make
deps/vecmath/CMakeFiles/vecmath.dir/src/vecio.cpp.o: ../deps/vecmath/src/vecio.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/重要文件/大二下/图形学/PA2_New/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object deps/vecmath/CMakeFiles/vecmath.dir/src/vecio.cpp.o"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vecmath.dir/src/vecio.cpp.o -c /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/vecio.cpp

deps/vecmath/CMakeFiles/vecmath.dir/src/vecio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vecmath.dir/src/vecio.cpp.i"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/vecio.cpp > CMakeFiles/vecmath.dir/src/vecio.cpp.i

deps/vecmath/CMakeFiles/vecmath.dir/src/vecio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vecmath.dir/src/vecio.cpp.s"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath/src/vecio.cpp -o CMakeFiles/vecmath.dir/src/vecio.cpp.s

# Object files for target vecmath
vecmath_OBJECTS = \
"CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o" \
"CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o" \
"CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o" \
"CMakeFiles/vecmath.dir/src/Quat4f.cpp.o" \
"CMakeFiles/vecmath.dir/src/Vector2f.cpp.o" \
"CMakeFiles/vecmath.dir/src/Vector3f.cpp.o" \
"CMakeFiles/vecmath.dir/src/Vector4f.cpp.o" \
"CMakeFiles/vecmath.dir/src/vecio.cpp.o"

# External object files for target vecmath
vecmath_EXTERNAL_OBJECTS =

deps/vecmath/libvecmath.a: deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix2f.cpp.o
deps/vecmath/libvecmath.a: deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix3f.cpp.o
deps/vecmath/libvecmath.a: deps/vecmath/CMakeFiles/vecmath.dir/src/Matrix4f.cpp.o
deps/vecmath/libvecmath.a: deps/vecmath/CMakeFiles/vecmath.dir/src/Quat4f.cpp.o
deps/vecmath/libvecmath.a: deps/vecmath/CMakeFiles/vecmath.dir/src/Vector2f.cpp.o
deps/vecmath/libvecmath.a: deps/vecmath/CMakeFiles/vecmath.dir/src/Vector3f.cpp.o
deps/vecmath/libvecmath.a: deps/vecmath/CMakeFiles/vecmath.dir/src/Vector4f.cpp.o
deps/vecmath/libvecmath.a: deps/vecmath/CMakeFiles/vecmath.dir/src/vecio.cpp.o
deps/vecmath/libvecmath.a: deps/vecmath/CMakeFiles/vecmath.dir/build.make
deps/vecmath/libvecmath.a: deps/vecmath/CMakeFiles/vecmath.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/e/重要文件/大二下/图形学/PA2_New/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library libvecmath.a"
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && $(CMAKE_COMMAND) -P CMakeFiles/vecmath.dir/cmake_clean_target.cmake
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vecmath.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
deps/vecmath/CMakeFiles/vecmath.dir/build: deps/vecmath/libvecmath.a

.PHONY : deps/vecmath/CMakeFiles/vecmath.dir/build

deps/vecmath/CMakeFiles/vecmath.dir/clean:
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath && $(CMAKE_COMMAND) -P CMakeFiles/vecmath.dir/cmake_clean.cmake
.PHONY : deps/vecmath/CMakeFiles/vecmath.dir/clean

deps/vecmath/CMakeFiles/vecmath.dir/depend:
	cd /mnt/e/重要文件/大二下/图形学/PA2_New/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/e/重要文件/大二下/图形学/PA2_New/code /mnt/e/重要文件/大二下/图形学/PA2_New/code/deps/vecmath /mnt/e/重要文件/大二下/图形学/PA2_New/code/build /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath /mnt/e/重要文件/大二下/图形学/PA2_New/code/build/deps/vecmath/CMakeFiles/vecmath.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : deps/vecmath/CMakeFiles/vecmath.dir/depend

