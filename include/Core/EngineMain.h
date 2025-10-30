#pragma once
#include "StackSingletons.h"
#include "Application/Application.h"
#include "Debugging/ImGUI/ImGUILayer.h"
#include "Rendering/Renderer.h"

extern Application* CreateApplication();

namespace Core
{
	inline auto& MainEventSystem = GetEventSystem();

	inline int RunEngine()
	{
		Rendering::Renderer* renderer = new Rendering::Renderer();
		Application* application = CreateApplication();
		application->Init();
		application->Run();

		delete application;
		return 0;
	}
}

