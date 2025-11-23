#pragma once
#include "Application/Application.h"

extern Application& CreateApplication();

namespace Core
{
	inline int RunEngine()
	{
		Application& application = CreateApplication();
		application.Init();
		application.Run();

		return 0;
	}
}

