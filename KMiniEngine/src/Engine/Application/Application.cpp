#include "Application.h"
#include <iostream>
#include "../Core/Layer.h"

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
}

Application::~Application()
{
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




