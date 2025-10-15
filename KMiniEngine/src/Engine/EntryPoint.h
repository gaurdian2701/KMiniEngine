#pragma once
#include "Application.h"
#ifdef TARGET_PLATFORM_WINDOWS

extern KMiniEngine::Application* KMiniEngine::CreateApplication();

int main(int argc, char** argv)
{
	return 0;
}
#endif