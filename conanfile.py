from conans import ConanFile, CMake

class BrickEngineConan(ConanFile):
    name = "BrickEngine"
    version = "0.1"
    license = "<Put the package license here>"
    author = "Roman Mateichuk roma.matei4uck@gmail.com"
    url = "https://github.com/RingoUA/BrickEngine"
    description = "https://github.com/RingoUA/BrickEngine/blob/master/README.md"
    topics = ("Game Engine", "OpenGL", "Vulkan")
    settings = "os", "compiler", "build_type", "arch"
    requires = "glfw/3.3.3", "spdlog/1.8.2"
    options = {
        "shared": [True, False],
        "fPIC": [True, False]
    }
    default_options = {
        "shared": False,
        "fPIC": True
    }
    generators = "cmake"
    exports_sources = "BrickEngine/*"
    _cmake = None

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def _configure_cmake(self):
        if not self._cmake:
            self._cmake = CMake(self)
            self._cmake.configure(source_folder="BrickEngine")
        return self._cmake

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()

    def package(self):
        cmake = self._configure_cmake()
        self.copy("*.h", dst="include", src="BrickEngine")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["BrickEngine"]
