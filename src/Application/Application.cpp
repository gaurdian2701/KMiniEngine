#include "Application/Application.h"
#include "Core/Layer.h"
#include "Application/Window.h"
#include "Renderer/Renderer.h"
#include <iostream>

#include "Debugging/ImGUI/ImGUILayer.h"


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

void Application::Init()
{
	PushLayers();
	AttachAllLayers();
}

void Application::PushLayers()
{
	PushLayer<ImGUILayer>();
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
	while (!glfwWindowShouldClose(MainWindow->GetGLFWWindow()))
	{
		UpdateApplication();

		MainWindow->PreUpdate();
		UpdateLayerList();
		MainWindow->PostUpdate();
	}

	InitiateShutdown();
}

void Application::UpdateLayerList()
{
	for (uint8_t i = 0; i < LayerList.size(); i++)
	{
		if (LayerList[i] != nullptr)
		{
			LayerList[i]->Update();
			LayerList[i]->Render();
		}
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
