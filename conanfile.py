from conans import ConanFile, CMake, CMakeToolchain


class modern_cmake(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake_find_package"

    # def configure(self):
    #     self.options["opencv"].with_gtk = False

    def requirements(self):
        self.requires("catch2/2.13.3")
        self.requires("eigen/3.3.9")
        self.requires("sfml/2.5.1@bincrafters/stable")
