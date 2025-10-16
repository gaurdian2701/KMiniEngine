#pragma once
#include "Application.h"

extern KMiniEngine::Application* KMiniEngine::CreateApplication();

int RunEngine()
{
	KMiniEngine::Application* application = KMiniEngine::CreateApplication();
	application->Run();
	delete application;
	return 0;
}
