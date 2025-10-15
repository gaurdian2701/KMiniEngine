#pragma once
#include "Core.h"

namespace KMiniEngine
{
	class KMINIENGINE_API Application
	{
	public:
		Application();
		~Application();
		void Run();
	};

	Application* CreateApplication();
};


