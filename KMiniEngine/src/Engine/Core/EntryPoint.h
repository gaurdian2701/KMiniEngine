#pragma once
#include "../Application/Application.h"

extern Application* CreateApplication();

int RunEngine()
{
	Application* application = CreateApplication();
	application->Run();
	delete application;
	return 0;
}
