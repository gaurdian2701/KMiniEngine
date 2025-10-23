#include "Window.h"
#include "../Scene/Camera/Camera.h"
#include <iostream>

void Framebuffer_Size_Callback(GLFWwindow* window, int width, int height);

Window::Window(int width, int height)
{
	
	m_window = glfwCreateWindow(width, height, "KMiniEngine Window", nullptr, nullptr);
	if (m_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	InitContextCallbacks();
}


void Window::InitContextCallbacks()
{
	glfwMakeContextCurrent(m_window);
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetFramebufferSizeCallback(m_window, Framebuffer_Size_Callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
	}
}


void Framebuffer_Size_Callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
