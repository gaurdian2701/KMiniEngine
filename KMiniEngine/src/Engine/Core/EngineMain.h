#pragma once
#include "../Application/Application.h"
#include "../Debugging/ImGUI/ImGUILayer.h"

extern Application* CreateApplication();

namespace Core
{
	int RunEngine()
	{
		Application* application = CreateApplication();
		application->PushLayer<ImGUILayer>();
		application->Run();
		delete application;
		return 0;
	}
}

