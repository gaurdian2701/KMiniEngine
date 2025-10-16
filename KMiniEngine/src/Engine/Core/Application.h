#pragma once

namespace KMiniEngine
{
	class Application
	{
	public:
		Application();
		~Application();
		void Run();
	};
	 
	Application* CreateApplication();
};


