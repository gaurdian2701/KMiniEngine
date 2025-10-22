#pragma once
#include "../Application/Application.h"
#include "../Debugging/ImGUI/ImGUILayer.h"
#include "../Renderer/Renderer.h"

extern Application* CreateApplication();

namespace Core
{
	int RunEngine()
	{
		Renderer* renderer = new Renderer();
		Application* application = CreateApplication();
		application->PushLayer<ImGUILayer>();
		application->Run();
		delete application;
		return 0;
	}
}

