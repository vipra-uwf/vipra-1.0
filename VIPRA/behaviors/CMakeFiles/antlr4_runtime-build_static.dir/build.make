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
CMAKE_SOURCE_DIR = /mnt/c/Users/gabeb/Research-Vipra/vipra/VIPRA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/gabeb/Research-Vipra/vipra/VIPRA

# Utility rule file for antlr4_runtime-build_static.

# Include the progress variables for this target.
include behaviors/CMakeFiles/antlr4_runtime-build_static.dir/progress.make

behaviors/CMakeFiles/antlr4_runtime-build_static: behaviors/antlr4_runtime/src/antlr4_runtime-stamp/antlr4_runtime-build_static


behaviors/antlr4_runtime/src/antlr4_runtime-stamp/antlr4_runtime-build_static:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/gabeb/Research-Vipra/vipra/VIPRA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Performing build_static step for 'antlr4_runtime'"
	cd /mnt/c/Users/gabeb/Research-Vipra/vipra/VIPRA/behaviors/antlr4_runtime/src/antlr4_runtime/runtime/Cpp && $(MAKE) antlr4_static
	cd /mnt/c/Users/gabeb/Research-Vipra/vipra/VIPRA/behaviors/antlr4_runtime/src/antlr4_runtime/runtime/Cpp && /usr/bin/cmake -E touch /mnt/c/Users/gabeb/Research-Vipra/vipra/VIPRA/behaviors/antlr4_runtime/src/antlr4_runtime-stamp/antlr4_runtime-build_static

antlr4_runtime-build_static: behaviors/CMakeFiles/antlr4_runtime-build_static
antlr4_runtime-build_static: behaviors/antlr4_runtime/src/antlr4_runtime-stamp/antlr4_runtime-build_static
antlr4_runtime-build_static: behaviors/CMakeFiles/antlr4_runtime-build_static.dir/build.make

.PHONY : antlr4_runtime-build_static

# Rule to build all files generated by this target.
behaviors/CMakeFiles/antlr4_runtime-build_static.dir/build: antlr4_runtime-build_static

.PHONY : behaviors/CMakeFiles/antlr4_runtime-build_static.dir/build

behaviors/CMakeFiles/antlr4_runtime-build_static.dir/clean:
	cd /mnt/c/Users/gabeb/Research-Vipra/vipra/VIPRA/behaviors && $(CMAKE_COMMAND) -P CMakeFiles/antlr4_runtime-build_static.dir/cmake_clean.cmake
.PHONY : behaviors/CMakeFiles/antlr4_runtime-build_static.dir/clean

behaviors/CMakeFiles/antlr4_runtime-build_static.dir/depend:
	cd /mnt/c/Users/gabeb/Research-Vipra/vipra/VIPRA && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/gabeb/Research-Vipra/vipra/VIPRA /mnt/c/Users/gabeb/Research-Vipra/vipra/VIPRA_Behaviors /mnt/c/Users/gabeb/Research-Vipra/vipra/VIPRA /mnt/c/Users/gabeb/Research-Vipra/vipra/VIPRA/behaviors /mnt/c/Users/gabeb/Research-Vipra/vipra/VIPRA/behaviors/CMakeFiles/antlr4_runtime-build_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : behaviors/CMakeFiles/antlr4_runtime-build_static.dir/depend
