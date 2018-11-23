################################################################################
### Project FuzzyCMake
################################################################################
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# Possible reason for cmake_minimum requirements
# CMake version requirements
# >= 3.9.6 : OpenMP::OpenMP_CXX, doxygen_add_docs
# >= 3.9.4 : INTERPROCEDURAL_OPTIMIZATION support
# >= 3.8.2 : CUDA as cmake languge
# >= 3.8.2 : cxx_std_11, cxx_std_14
# >= 3.1.0 : Threads::Threads

project(libFUZZY VERSION 0.1 LANGUAGES CXX)

### libFUZZY as Module
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/shared/cmake")

### Set Build Types options, default is Release
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Release' as none was specified.")
  set(CMAKE_BUILD_TYPE "Release" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
      "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif ()


################################################################################

### Compiler Flags
# E.g. Vectorization for Eigen
option(FUZZY_WITH_MARCH_NATIVE "Use compiler flag -march=native if available" ON)
if (FUZZY_WITH_MARCH_NATIVE)
  # look for -march=native support for CPU vectorization
  include(CheckCXXCompilerFlag)
  CHECK_CXX_COMPILER_FLAG("-march=native" COMPILER_SUPPORTS_MARCH_NATIVE)
  if (COMPILER_SUPPORTS_MARCH_NATIVE)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native")
  endif ()
endif ()

### Warnings
if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif ()

### Adding libFUZZY
include(libfuzzy)

fuzzy_print_summary()

