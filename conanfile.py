from conans import ConanFile, CMake, CMakeToolchain


class modern_cmake(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = ("catch2/2.13.3",)
    generators = "cmake_find_package"

    def toolchain(self):
        tc = CMakeToolchain(self)
        tc.write_toolchain_files()
