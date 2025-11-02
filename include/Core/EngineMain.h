#pragma once
#include "Application/Application.h"
#include "Debugging/ImGUI/ImGUILayer.h"
#include "Events/EventSystem.h"
#include "Rendering/Renderer.h"

extern Application* CreateApplication();

namespace Core
{
	inline int RunEngine()
	{
		Rendering::Renderer* renderer = new Rendering::Renderer();
		Events::EventSystem* eventSystem = new Events::EventSystem();
		Application* application = CreateApplication();
		application->Init();
		application->Run();

		delete application;
		return 0;
	}
}

