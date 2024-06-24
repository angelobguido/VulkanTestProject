cmake_minimum_required(VERSION 3.28)
project(vulkan)

set(CMAKE_CXX_STANDARD 17)

# Find the Vulkan package
find_package(Vulkan REQUIRED)

# Find the GLFW3 package
find_package(glfw3 3.3 REQUIRED)

# Find the GLM package
find_package(glm REQUIRED)

add_executable(vulkan main.cpp
        source/App.cpp
        source/App.h
        source/stb_image/stb_image.h)

# Link Vulkan, GLFW and GLM to the executable
target_link_libraries(vulkan Vulkan::Vulkan)
target_link_libraries(vulkan glfw)
target_link_libraries(vulkan glm::glm)