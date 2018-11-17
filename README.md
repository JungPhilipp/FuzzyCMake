# FuzzyCMake
libFuzzy CMake is a small CMake project that aims to show how to setup a modern CMake project.
The structure is partly adapted from libigl (https://github.com/libigl/libigl).

The overall structure looks like this:
```
FuzzeCMake
|
└─── shared
|   └─── cmake
|
└─── examples
|   └─── exp0
|
└─── include
|   └───fuzzy
|
└─── src
|   └─── fuzzy
|
└─── tests
|
|
└─── third_party
    └─── catch2
    └─── easylogging
    └─── eigen
    └─── eigen_util
```
The CMake structure looks similar:
### fuzzy_core
Like the name suggests, this contains the core code of libFuzzy.
Other targets using parts are simply linked against fuzzy_core.
fuzzy_core also includes are core dependencies, which are bundled in fuzzy_common.

### fuzzy_common
The fuzzy_common serves as a collection of libraries against which other targets link.
In this case it includes Boost, Catch2, Easylogging, Eigen and OpenMP(if enabled).
To add new dependencies (such as cereal or ligigl) can simply be added to this target.
For more special use-cases (such as vtk or paraview) one should add another library.

### third_party
Dependencies used with fuzzy_common are managed and build within the third_party folder.
To add a new dependency, add the source directly are init. a git submodule and append the CMakeLists.txt.
### fuzzy_tests
Includes tests for the core codes (from fuzzy_core). If new parts of the library are added (lets say fuzzy_vtk),
one would simply add another test target.

### Examples
Examples are separated into individual folders with their own CMakeLists.txt.
For each example the user decides which libs to use. In this simple case, we just link against fuzzy_core.


### TODO
Instead of copying code for third_party dependencies, git submodules should be used.
Git Submodules for third_party (soon)

For CI/CD purposes a travis.yml config file is required
Travis config (soon)
