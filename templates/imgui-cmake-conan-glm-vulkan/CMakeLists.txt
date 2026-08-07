cmake_minimum_required(VERSION 3.15)
project(ImGuiVulkanApp CXX)

find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
#find_package(Vulkan REQUIRED)
find_package(VulkanHeaders CONFIG REQUIRED)
find_package(VulkanLoader CONFIG REQUIRED)

add_executable(app main.cpp)

target_link_libraries(app PRIVATE 
  imgui::imgui
  glfw
#  Vulkan::Vulkan
  Vulkan::Headers
  Vulkan::Loader
)

target_include_directories(app PRIVATE 
  ${IMGUI_BND_DIR}
  ${IMGUI_INC_DIR}
)
target_sources(app PRIVATE 
  ${IMGUI_SRC_DIR}/imgui.cpp
  ${IMGUI_SRC_DIR}/imgui_draw.cpp
  ${IMGUI_SRC_DIR}/imgui_tables.cpp
  ${IMGUI_SRC_DIR}/imgui_widgets.cpp
  ${IMGUI_BND_DIR}/imgui_impl_glfw.cpp
  ${IMGUI_BND_DIR}/imgui_impl_vulkan.cpp
)
