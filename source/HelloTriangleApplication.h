#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <optional>

namespace app {

    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

    const std::vector<const char*> validationLayers = {
            "VK_LAYER_KHRONOS_validation"
    };

    #ifdef NDEBUG
        const bool enableValidationLayers = false;
    #else
        const bool enableValidationLayers = true;
    #endif

    struct QueueFamilyIndices {
         std::optional<uint32_t> graphicsFamily;

         bool isComplete() {
             return graphicsFamily.has_value();
         }
    };

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    bool isDeviceSuitable(VkPhysicalDevice device);

    bool checkValidationLayerSupport();

    class HelloTriangleApplication {

    private:
        GLFWwindow* window;
        VkInstance instance;
        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
        VkDevice device;
        VkQueue graphicsQueue;

    public:
        void run();

    private:

        void initWindow();

        void initVulkan();

        void createInstance();

        void mainLoop();

        void cleanup();

        void pickPhysicalDevice();

        void createLogicalDevice();

    };


}
