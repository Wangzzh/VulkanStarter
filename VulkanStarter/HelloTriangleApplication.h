#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <optional>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

struct QueueFamilyIndices {
	std::optional<uint32_t> graphisFamily;
	bool isComplete();
};

class HelloTriangleApplication
{
public:
	void run();

private:
	void initVulkan();
	void createInstance();
	void pickupPhysicalDevice();
	bool isDeviceSuitable(VkPhysicalDevice device);

	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

	void initWindow();
	void mainLoop();
	void cleanUp();

	bool checkValidationLayerSupport();

	GLFWwindow* window;
	VkInstance instance;

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

