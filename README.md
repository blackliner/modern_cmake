# modern_cmake
Modern CMake Project template with conan as dependency management

# Setup

     pip3 install conan

Follow [kitware cmake install tutorial](https://apt.kitware.com/) to install a more recent version of cmake (3.19.1).

     sudo apt-get --only-upgrade install cmake

# Build

     mkdir build
     cd build
     conan install ..
     cmake .. -DCMAKE_MODULE_PATH=${PWD} -G Ninja -DCMAKE_BUILD_TYPE=Release
     ninja
