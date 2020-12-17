# modern_cmake
Modern CMake Project template with conan as dependency management

# Setup

     pip3 install conan

Follow [kitware cmake install tutorial](https://apt.kitware.com/) to install a more recent version of cmake (3.19.1).

     sudo apt-get --only-upgrade install cmake

# Build
call `pipeline.sh` or:
```bash
mkdir build
cd build
conan install ..
cmake .. -DCMAKE_MODULE_PATH=${PWD} -G Ninja -DCMAKE_BUILD_TYPE=Release
ninja
```

# Troubleshooting
Downgrading cmake can be necessary if you have issues with newer versions.

The current default version for ubuntu 18.04.1 LTS is 3.10.2.

Using this command you can downgrade:
```sudo apt --allow-downgrades install cmake=3.10.2 cmake-data=3.10.2```
