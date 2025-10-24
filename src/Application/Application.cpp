#include "Application/Application.h"
#include "Core/Layer.h"
#include "Application/Window.h"
#include "Renderer/Renderer.h"
#include <iostream>


Application* Application::ApplicationInstance = nullptr;
std::unique_ptr<Window> Application::MainWindow = std::make_unique<Window>(1000, 800);
std::vector<std::unique_ptr<Layer>> Application::LayerList;


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
	return LayerList;
}

Window* Application::GetMainWindow()
{
	return MainWindow.get();
}
