#pragma once


class Application
{
public:
	Application();
	~Application();
	virtual void Run();
};

Application* CreateApplication();



