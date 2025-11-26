#include "Application/Window.h"
#include <iostream>
#include "Rendering/RenderConfigs.h"


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
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	glfwSetFramebufferSizeCallback(m_window, Framebuffer_Size_Callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
	}
}

void Window::PreUpdate()
{
	glfwPollEvents();
	ProcessInput();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(Rendering::BACKGROUND_COLOUR.x, Rendering::BACKGROUND_COLOUR.y, Rendering::BACKGROUND_COLOUR.z, Rendering::BACKGROUND_COLOUR.w);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_CULL_FACE);
}

void Window::PostUpdate()
{
	glfwSwapBuffers(m_window);
}


GLFWwindow* Window::GetGLFWWindow()
{
	return m_window;
}

void Framebuffer_Size_Callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Window::ProcessInput()
{
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_window, true);
	}
}
