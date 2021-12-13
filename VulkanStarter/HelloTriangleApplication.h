#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <set>
#include <optional>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

struct QueueFamilyIndices {
public:
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;
	bool isComplete();
};

class HelloTriangleApplication
{
public:
	void run();

private:
	void initVulkan();
	void createInstance();
	void createSurface();
	void pickupPhysicalDevice();
	bool isDeviceSuitable(VkPhysicalDevice physicalDevice);

	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice physicalDevice);
	void createLogicalDevice();

	void initWindow();
	void mainLoop();
	void cleanUp();

	bool checkValidationLayerSupport();

	GLFWwindow* window;
	VkInstance instance;
	VkPhysicalDevice physicalDevice;
	VkDevice device;
	VkQueue graphicsQueue;
	VkQueue presentQueue;

	VkSurfaceKHR surface;

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
};

