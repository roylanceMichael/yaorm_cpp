# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.5.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.5.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mroylance/yaorm_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mroylance/yaorm_cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/yaorm_cpp_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/yaorm_cpp_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/yaorm_cpp_test.dir/flags.make

CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.o: CMakeFiles/yaorm_cpp_test.dir/flags.make
CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.o: ../src/cpp/models/yaorm_models.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mroylance/yaorm_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.o -c /Users/mroylance/yaorm_cpp/src/cpp/models/yaorm_models.pb.cc

CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mroylance/yaorm_cpp/src/cpp/models/yaorm_models.pb.cc > CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.i

CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mroylance/yaorm_cpp/src/cpp/models/yaorm_models.pb.cc -o CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.s

CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.o.requires:

.PHONY : CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.o.requires

CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.o.provides: CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.o.requires
	$(MAKE) -f CMakeFiles/yaorm_cpp_test.dir/build.make CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.o.provides.build
.PHONY : CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.o.provides

CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.o.provides.build: CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.o


CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.o: CMakeFiles/yaorm_cpp_test.dir/flags.make
CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.o: ../src/cpp/services/sqlite/sqlite_generator_service.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mroylance/yaorm_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.o -c /Users/mroylance/yaorm_cpp/src/cpp/services/sqlite/sqlite_generator_service.cpp

CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mroylance/yaorm_cpp/src/cpp/services/sqlite/sqlite_generator_service.cpp > CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.i

CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mroylance/yaorm_cpp/src/cpp/services/sqlite/sqlite_generator_service.cpp -o CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.s

CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.o.requires:

.PHONY : CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.o.requires

CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.o.provides: CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.o.requires
	$(MAKE) -f CMakeFiles/yaorm_cpp_test.dir/build.make CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.o.provides.build
.PHONY : CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.o.provides

CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.o.provides.build: CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.o


CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.o: CMakeFiles/yaorm_cpp_test.dir/flags.make
CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.o: ../src/cpp/models/sqlite_models.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mroylance/yaorm_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.o -c /Users/mroylance/yaorm_cpp/src/cpp/models/sqlite_models.pb.cc

CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mroylance/yaorm_cpp/src/cpp/models/sqlite_models.pb.cc > CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.i

CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mroylance/yaorm_cpp/src/cpp/models/sqlite_models.pb.cc -o CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.s

CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.o.requires:

.PHONY : CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.o.requires

CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.o.provides: CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.o.requires
	$(MAKE) -f CMakeFiles/yaorm_cpp_test.dir/build.make CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.o.provides.build
.PHONY : CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.o.provides

CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.o.provides.build: CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.o


CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.o: CMakeFiles/yaorm_cpp_test.dir/flags.make
CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.o: ../src/cpp/utilities/common_sql_utilities.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mroylance/yaorm_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.o -c /Users/mroylance/yaorm_cpp/src/cpp/utilities/common_sql_utilities.cpp

CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mroylance/yaorm_cpp/src/cpp/utilities/common_sql_utilities.cpp > CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.i

CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mroylance/yaorm_cpp/src/cpp/utilities/common_sql_utilities.cpp -o CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.s

CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.o.requires:

.PHONY : CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.o.requires

CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.o.provides: CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.o.requires
	$(MAKE) -f CMakeFiles/yaorm_cpp_test.dir/build.make CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.o.provides.build
.PHONY : CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.o.provides

CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.o.provides.build: CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.o


CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.o: CMakeFiles/yaorm_cpp_test.dir/flags.make
CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.o: ../src/test/sqlite/sqlite_generator_service_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mroylance/yaorm_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.o -c /Users/mroylance/yaorm_cpp/src/test/sqlite/sqlite_generator_service_tests.cpp

CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mroylance/yaorm_cpp/src/test/sqlite/sqlite_generator_service_tests.cpp > CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.i

CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mroylance/yaorm_cpp/src/test/sqlite/sqlite_generator_service_tests.cpp -o CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.s

CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.o.requires:

.PHONY : CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.o.requires

CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.o.provides: CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.o.requires
	$(MAKE) -f CMakeFiles/yaorm_cpp_test.dir/build.make CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.o.provides.build
.PHONY : CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.o.provides

CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.o.provides.build: CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.o


CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.o: CMakeFiles/yaorm_cpp_test.dir/flags.make
CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.o: ../src/test/test_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mroylance/yaorm_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.o -c /Users/mroylance/yaorm_cpp/src/test/test_main.cpp

CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mroylance/yaorm_cpp/src/test/test_main.cpp > CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.i

CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mroylance/yaorm_cpp/src/test/test_main.cpp -o CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.s

CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.o.requires:

.PHONY : CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.o.requires

CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.o.provides: CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.o.requires
	$(MAKE) -f CMakeFiles/yaorm_cpp_test.dir/build.make CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.o.provides.build
.PHONY : CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.o.provides

CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.o.provides.build: CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.o


# Object files for target yaorm_cpp_test
yaorm_cpp_test_OBJECTS = \
"CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.o" \
"CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.o" \
"CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.o" \
"CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.o" \
"CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.o" \
"CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.o"

# External object files for target yaorm_cpp_test
yaorm_cpp_test_EXTERNAL_OBJECTS =

yaorm_cpp_test: CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.o
yaorm_cpp_test: CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.o
yaorm_cpp_test: CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.o
yaorm_cpp_test: CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.o
yaorm_cpp_test: CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.o
yaorm_cpp_test: CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.o
yaorm_cpp_test: CMakeFiles/yaorm_cpp_test.dir/build.make
yaorm_cpp_test: CMakeFiles/yaorm_cpp_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mroylance/yaorm_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable yaorm_cpp_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yaorm_cpp_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/yaorm_cpp_test.dir/build: yaorm_cpp_test

.PHONY : CMakeFiles/yaorm_cpp_test.dir/build

CMakeFiles/yaorm_cpp_test.dir/requires: CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/yaorm_models.pb.cc.o.requires
CMakeFiles/yaorm_cpp_test.dir/requires: CMakeFiles/yaorm_cpp_test.dir/src/cpp/services/sqlite/sqlite_generator_service.cpp.o.requires
CMakeFiles/yaorm_cpp_test.dir/requires: CMakeFiles/yaorm_cpp_test.dir/src/cpp/models/sqlite_models.pb.cc.o.requires
CMakeFiles/yaorm_cpp_test.dir/requires: CMakeFiles/yaorm_cpp_test.dir/src/cpp/utilities/common_sql_utilities.cpp.o.requires
CMakeFiles/yaorm_cpp_test.dir/requires: CMakeFiles/yaorm_cpp_test.dir/src/test/sqlite/sqlite_generator_service_tests.cpp.o.requires
CMakeFiles/yaorm_cpp_test.dir/requires: CMakeFiles/yaorm_cpp_test.dir/src/test/test_main.cpp.o.requires

.PHONY : CMakeFiles/yaorm_cpp_test.dir/requires

CMakeFiles/yaorm_cpp_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/yaorm_cpp_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/yaorm_cpp_test.dir/clean

CMakeFiles/yaorm_cpp_test.dir/depend:
	cd /Users/mroylance/yaorm_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mroylance/yaorm_cpp /Users/mroylance/yaorm_cpp /Users/mroylance/yaorm_cpp/build /Users/mroylance/yaorm_cpp/build /Users/mroylance/yaorm_cpp/build/CMakeFiles/yaorm_cpp_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/yaorm_cpp_test.dir/depend

