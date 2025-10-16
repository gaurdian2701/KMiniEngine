#pragma once
#include "Application.h"
#ifdef TARGET_PLATFORM_WINDOWS

extern KMiniEngine::Application* KMiniEngine::CreateApplication();

int RunEngine()
{
	KMiniEngine::Application* application = KMiniEngine::CreateApplication();
	application->Run();
	delete application;
	return 0;
}
#endif