# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /cvmfs/larsoft.opensciencegrid.org/products/cmake/v3_10_1/Linux64bit+2.6-2.12/bin/cmake

# The command to remove a file.
RM = /cvmfs/larsoft.opensciencegrid.org/products/cmake/v3_10_1/Linux64bit+2.6-2.12/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE/build

# Include any dependencies generated for this target.
include CMakeFiles/gallery_SCEcorrections.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gallery_SCEcorrections.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gallery_SCEcorrections.dir/flags.make

CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.o: CMakeFiles/gallery_SCEcorrections.dir/flags.make
CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.o: ../gallery_SCEcorrections.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.o"
	/cvmfs/larsoft.opensciencegrid.org/products/gcc/v7_3_0/Linux64bit+2.6-2.12/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.o -c /sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE/gallery_SCEcorrections.cpp

CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.i"
	/cvmfs/larsoft.opensciencegrid.org/products/gcc/v7_3_0/Linux64bit+2.6-2.12/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE/gallery_SCEcorrections.cpp > CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.i

CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.s"
	/cvmfs/larsoft.opensciencegrid.org/products/gcc/v7_3_0/Linux64bit+2.6-2.12/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE/gallery_SCEcorrections.cpp -o CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.s

CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.o.requires:

.PHONY : CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.o.requires

CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.o.provides: CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.o.requires
	$(MAKE) -f CMakeFiles/gallery_SCEcorrections.dir/build.make CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.o.provides.build
.PHONY : CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.o.provides

CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.o.provides.build: CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.o


# Object files for target gallery_SCEcorrections
gallery_SCEcorrections_OBJECTS = \
"CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.o"

# External object files for target gallery_SCEcorrections
gallery_SCEcorrections_EXTERNAL_OBJECTS =

gallery_SCEcorrections: CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.o
gallery_SCEcorrections: CMakeFiles/gallery_SCEcorrections.dir/build.make
gallery_SCEcorrections: CMakeFiles/gallery_SCEcorrections.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gallery_SCEcorrections"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gallery_SCEcorrections.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gallery_SCEcorrections.dir/build: gallery_SCEcorrections

.PHONY : CMakeFiles/gallery_SCEcorrections.dir/build

CMakeFiles/gallery_SCEcorrections.dir/requires: CMakeFiles/gallery_SCEcorrections.dir/gallery_SCEcorrections.cpp.o.requires

.PHONY : CMakeFiles/gallery_SCEcorrections.dir/requires

CMakeFiles/gallery_SCEcorrections.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gallery_SCEcorrections.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gallery_SCEcorrections.dir/clean

CMakeFiles/gallery_SCEcorrections.dir/depend:
	cd /sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE /sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE /sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE/build /sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE/build /sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE/build/CMakeFiles/gallery_SCEcorrections.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gallery_SCEcorrections.dir/depend

