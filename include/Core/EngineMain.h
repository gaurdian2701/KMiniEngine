#pragma once
#include "StackSingletons.h"
#include "Application/Application.h"
#include "Renderer/Renderer.h"

extern Application* CreateApplication();

namespace Core
{
	inline int RunEngine()
	{
		Renderer* renderer = new Renderer();

		auto& MainEventSystem = GetEventSystem();

		Application* application = CreateApplication();
		application->Init();
		application->Run();

		delete application;
		return 0;
	}
}

