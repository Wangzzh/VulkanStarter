#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


class HelloTriangleApplication
{
public:
	void run();

private:
	void initVulkan();
	void createInstance();
	void initWindow();
	void mainLoop();
	void cleanUp();

	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;

	GLFWwindow* window;

	VkInstance instance;
};

