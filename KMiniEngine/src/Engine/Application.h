#pragma once
#include "Core.h"

namespace KMiniEngine
{
	class KMINIENGINE_API Application
	{
	public:
		Application();
		~Application();
		virtual void Run();
	};

	Application* CreateApplication();
}


