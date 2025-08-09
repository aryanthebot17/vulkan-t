#pragma once

#include<vulkan/vulkan.h>
#include <GLFW/glfw3.h>  
#include <iostream> 
#include <stdexcept>
#include<cstdlib>


// strucure
// namespace:: vulk
// StartVulkan class

//namespace vulk {

	// now create StartVulkan class

class StartVulkan {

private:
	// the Vkinstane method will attack vulkan api ptr with  "instance"

	VkInstance instance;

public:
	// default constructor
	 StartVulkan() {

	}

	void createInstance() {
		// app will store the instance info
		VkApplicationInfo app{};

		app.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		app.pApplicationName = "vulkan app";
		app.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		app.pEngineName = "No Engine";
		app.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		app.apiVersion = VK_API_VERSION_1_0;

		VkInstanceCreateInfo createInfo{};

		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &app;

		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions =
			glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
		createInfo.enabledExtensionCount = glfwExtensionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;


		createInfo.enabledLayerCount = 0;

		// link the vk_instance to instance object
		//VkInstance instance;

		VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

		if (result != VK_SUCCESS)

		{
			throw std::runtime_error("not able to get the instance of vulkan");
		}
		std::cout << "sucessfully created instance vulkan";
	}







};





	

