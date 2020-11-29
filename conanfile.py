from conans import ConanFile, CMake, CMakeToolchain


class modern_cmake(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = ("catch2/2.13.3",)
    generators = "cmake_find_package"
