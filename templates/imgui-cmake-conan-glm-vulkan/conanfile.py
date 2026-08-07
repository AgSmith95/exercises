#conan install conanfile.py --build=missing
#conan build conanfile.py --build=missing

import os
from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout, CMakeToolchain

class ImGuiVulkanApp(ConanFile):
    name = "imgui-vulkan-app"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps"

    def requirements(self):
        self.requires("imgui/1.92.9b-docking")
        self.requires("glfw/3.4")
        # Vulkan requires both the headers and the loader library
        self.requires("vulkan-headers/1.3.268.0")
        self.requires("vulkan-loader/1.3.268.0")

    def configure(self):
        # Tell Conan to pre-compile the correct ImGui backends
        self.options["imgui"].with_glfw = True
        self.options["imgui"].with_vulkan = True

    def layout(self):
        cmake_layout(self)

    def generate(self):
        # 1. Ask Conan where the imgui package is stored in the local cache
        imgui_pkg = self.dependencies["imgui"].package_folder
        inc_dirs = os.path.join(imgui_pkg, "res", "include")
        bnd_dirs = os.path.join(imgui_pkg, "res", "bindings")
        src_dirs = os.path.join(imgui_pkg, "res", "src")

        # 2. Inject this path into CMakeToolchain
        tc = CMakeToolchain(self)
        tc.variables["IMGUI_INC_DIR"] = inc_dirs.replace("\\", "/") # replace '\' with '/' for WIN compatibility
        tc.variables["IMGUI_BND_DIR"] = bnd_dirs.replace("\\", "/") # replace '\' with '/' for WIN compatibility
        tc.variables["IMGUI_SRC_DIR"] = src_dirs.replace("\\", "/") # replace '\' with '/' for WIN compatibility
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

