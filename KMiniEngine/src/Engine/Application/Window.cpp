#include "Window.h"
#include "../Renderer/Camera/Camera.h"
#include <iostream>

Window::Window(int width, int height)
{
	InitializeOpenGLContext();

	m_window = glfwCreateWindow(width, height, "KMiniEngine Window", nullptr, nullptr);
	if (m_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
}

void Window::InitializeOpenGLContext()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwSwapInterval(0);
}	

void Window::InitContextCallbacks()
{
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwMakeContextCurrent(m_window);
	//glfwSetFramebufferSizeCallback(m_window, Framebuffer_Size_Callback);
	//glfwSetCursorPosCallback(m_window, Mouse_Callback);

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
