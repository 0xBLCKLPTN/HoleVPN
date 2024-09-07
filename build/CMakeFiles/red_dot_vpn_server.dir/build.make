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
CMAKE_SOURCE_DIR = /home/twofacedjanus/Documents/HoleVPN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/twofacedjanus/Documents/HoleVPN/build

# Include any dependencies generated for this target.
include CMakeFiles/red_dot_vpn_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/red_dot_vpn_server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/red_dot_vpn_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/red_dot_vpn_server.dir/flags.make

CMakeFiles/red_dot_vpn_server.dir/vpn_server/main.c.o: CMakeFiles/red_dot_vpn_server.dir/flags.make
CMakeFiles/red_dot_vpn_server.dir/vpn_server/main.c.o: ../vpn_server/main.c
CMakeFiles/red_dot_vpn_server.dir/vpn_server/main.c.o: CMakeFiles/red_dot_vpn_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/twofacedjanus/Documents/HoleVPN/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/red_dot_vpn_server.dir/vpn_server/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/red_dot_vpn_server.dir/vpn_server/main.c.o -MF CMakeFiles/red_dot_vpn_server.dir/vpn_server/main.c.o.d -o CMakeFiles/red_dot_vpn_server.dir/vpn_server/main.c.o -c /home/twofacedjanus/Documents/HoleVPN/vpn_server/main.c

CMakeFiles/red_dot_vpn_server.dir/vpn_server/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/red_dot_vpn_server.dir/vpn_server/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/twofacedjanus/Documents/HoleVPN/vpn_server/main.c > CMakeFiles/red_dot_vpn_server.dir/vpn_server/main.c.i

CMakeFiles/red_dot_vpn_server.dir/vpn_server/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/red_dot_vpn_server.dir/vpn_server/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/twofacedjanus/Documents/HoleVPN/vpn_server/main.c -o CMakeFiles/red_dot_vpn_server.dir/vpn_server/main.c.s

CMakeFiles/red_dot_vpn_server.dir/cryptography/cryptography.c.o: CMakeFiles/red_dot_vpn_server.dir/flags.make
CMakeFiles/red_dot_vpn_server.dir/cryptography/cryptography.c.o: ../cryptography/cryptography.c
CMakeFiles/red_dot_vpn_server.dir/cryptography/cryptography.c.o: CMakeFiles/red_dot_vpn_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/twofacedjanus/Documents/HoleVPN/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/red_dot_vpn_server.dir/cryptography/cryptography.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/red_dot_vpn_server.dir/cryptography/cryptography.c.o -MF CMakeFiles/red_dot_vpn_server.dir/cryptography/cryptography.c.o.d -o CMakeFiles/red_dot_vpn_server.dir/cryptography/cryptography.c.o -c /home/twofacedjanus/Documents/HoleVPN/cryptography/cryptography.c

CMakeFiles/red_dot_vpn_server.dir/cryptography/cryptography.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/red_dot_vpn_server.dir/cryptography/cryptography.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/twofacedjanus/Documents/HoleVPN/cryptography/cryptography.c > CMakeFiles/red_dot_vpn_server.dir/cryptography/cryptography.c.i

CMakeFiles/red_dot_vpn_server.dir/cryptography/cryptography.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/red_dot_vpn_server.dir/cryptography/cryptography.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/twofacedjanus/Documents/HoleVPN/cryptography/cryptography.c -o CMakeFiles/red_dot_vpn_server.dir/cryptography/cryptography.c.s

# Object files for target red_dot_vpn_server
red_dot_vpn_server_OBJECTS = \
"CMakeFiles/red_dot_vpn_server.dir/vpn_server/main.c.o" \
"CMakeFiles/red_dot_vpn_server.dir/cryptography/cryptography.c.o"

# External object files for target red_dot_vpn_server
red_dot_vpn_server_EXTERNAL_OBJECTS =

red_dot_vpn_server: CMakeFiles/red_dot_vpn_server.dir/vpn_server/main.c.o
red_dot_vpn_server: CMakeFiles/red_dot_vpn_server.dir/cryptography/cryptography.c.o
red_dot_vpn_server: CMakeFiles/red_dot_vpn_server.dir/build.make
red_dot_vpn_server: CMakeFiles/red_dot_vpn_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/twofacedjanus/Documents/HoleVPN/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable red_dot_vpn_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/red_dot_vpn_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/red_dot_vpn_server.dir/build: red_dot_vpn_server
.PHONY : CMakeFiles/red_dot_vpn_server.dir/build

CMakeFiles/red_dot_vpn_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/red_dot_vpn_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/red_dot_vpn_server.dir/clean

CMakeFiles/red_dot_vpn_server.dir/depend:
	cd /home/twofacedjanus/Documents/HoleVPN/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/twofacedjanus/Documents/HoleVPN /home/twofacedjanus/Documents/HoleVPN /home/twofacedjanus/Documents/HoleVPN/build /home/twofacedjanus/Documents/HoleVPN/build /home/twofacedjanus/Documents/HoleVPN/build/CMakeFiles/red_dot_vpn_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/red_dot_vpn_server.dir/depend
