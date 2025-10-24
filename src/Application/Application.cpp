#include "Application/Application.h"
#include "Core/Layer.h"
#include "Application/Window.h"
#include <iostream>
#include "Renderer/Renderer.h"

Application* Application::ApplicationInstance = nullptr;


Application::Application()
{
	if (ApplicationInstance != nullptr)
	{
		std::cout << "Application already exists!" << "\n";
	}
	else
	{
		ApplicationInstance = this;
	}

	m_renderer = std::make_unique<Renderer>();
	m_mainWindow = std::make_unique<Window>(1000, 800);
}

void Application::Run()
{
	while (true)
	{
	}
}

Application* Application::GetInstance()
{
	return ApplicationInstance;
}

std::vector<std::unique_ptr<Layer>>& Application::GetLayerList()
{
	return m_LayerList;
}

Window* Application::GetMainWindow()
{
	return m_mainWindow.get();
}
