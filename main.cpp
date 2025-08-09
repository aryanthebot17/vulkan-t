#include <GLFW/glfw3.h>  
#include <iostream>    
#include<vulkan/vulkan.h>
#include<stdexcept>
#include<cstdlib>
#define GLFW_INCLUDE_VULKAN
#include "Vulkan_instance.hpp"


int main() {

    // creating vulkan instance
    StartVulkan instance_1 =  StartVulkan();
	// call the createInstance method
	instance_1.createInstance();


    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!\n";
        return -1;
    }
    

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

  
    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan Window", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window!\n";
        glfwTerminate();
        return -1;
    }


    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
