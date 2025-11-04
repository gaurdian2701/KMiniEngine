#include "Application/Application.h"
#include "Core/Layer.h"
#include "Application/Window.h"
#include <iostream>
#include "Debugging/ImGUI/ImGUILayer.h"
#include "IO/Input/InputSystem.h"

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

	MainWindow = new Window(1000, 800);
}

Application::~Application()
{
	delete MainWindow;
}

Application* Application::GetInstance()
{
	return ApplicationInstance;
}

void Application::Init()
{
	PushLayers();
	AttachAllLayers();
}

void Application::PushLayers()
{
	PushLayer<IO::Input::InputSystem>();
	PushLayer<Debugging::ImGUI::ImGUILayer>();
}

void Application::AttachAllLayers()
{
	for (uint8_t i = 0; i < LayerList.size(); i++)
	{
		LayerList[i]->OnAttach();
	}
}

void Application::Run()
{
	BeginApplication();
	while (!glfwWindowShouldClose(MainWindow->GetGLFWWindow()))
	{
		UpdateApplication();

		MainWindow->PreUpdate();
		UpdateLayerList();
		MainWindow->PostUpdate();
	}

	EndApplication();
	InitiateShutdown();
}

void Application::UpdateLayerList()
{
	for (uint32_t i = 0; i < LayerList.size(); i++)
	{
		if (LayerList[i] != nullptr)
		{
			LayerList[i]->Update();
			LayerList[i]->Render();
			LayerList[i]->ProcessInput();
		}
	}
}

std::vector<std::unique_ptr<Core::Layer>>& Application::GetLayerList()
{
	return LayerList;
}

Window* Application::GetMainWindow()
{
	return MainWindow;
}

void Application::DetachAllLayers()
{
	for (uint8_t i = 0; i < LayerList.size(); i++)
	{
		if (LayerList[i] != nullptr)
		{
			LayerList[i]->OnDetach();
		}
	}
}

void Application::CloseGLFWWindow()
{
	glfwDestroyWindow(MainWindow->GetGLFWWindow());
	glfwTerminate();
}

void Application::InitiateShutdown()
{
	DetachAllLayers();
	CloseGLFWWindow();
}
