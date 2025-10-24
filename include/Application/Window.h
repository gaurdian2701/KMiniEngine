#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../Core/Layer.h"

class Window : public Layer
{
public:
	Window(int width, int height);
	~Window();
	void InitContextCallbacks();
	GLFWwindow* GetGLFWWindow();

private:
	GLFWwindow* m_window = nullptr;
};