cmake_minimum_required(VERSION 3.28)
project(vulkan)

set(CMAKE_CXX_STANDARD 17)

# Find the Vulkan package
find_package(Vulkan REQUIRED)

add_executable(vulkan main.cpp
        source/App.cpp
        source/App.h
        source/stb_image/stb_image.h
        source/obj_loader/tiny_obj_loader.h)

# Link Vulkan, GLFW and GLM to the executable
target_link_libraries(vulkan Vulkan::Vulkan)
target_link_libraries(vulkan -lglfw3)