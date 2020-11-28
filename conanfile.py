from conans import ConanFile, CMake


class Deps(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = (
        "catch2/2.13.3",
    )
    generators = "cmake_find_package"
