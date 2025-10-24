#include "Application/Window.h"
#include <iostream>
#include "GLFW/glfw3.h"

void Framebuffer_Size_Callback(GLFWwindow* window, int width, int height);

Window::Window(int width, int height)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwSwapInterval(0);

	m_window = glfwCreateWindow(width, height, "KMiniEngine Window", nullptr, nullptr);
	if (m_window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	InitContextCallbacks();
}

Window::~Window()
{
	glfwTerminate();
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

GLFWwindow* Window::GetGLFWWindow()
{
	return m_window;
}


void Framebuffer_Size_Callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
