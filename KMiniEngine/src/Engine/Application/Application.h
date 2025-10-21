#pragma once
#include <vector>
#include <memory>


class Layer;

class Application
{
public:
	Application();
	~Application();
	Application(const Application& other) = delete;

	virtual void Run();
	std::vector<std::unique_ptr<Layer>>& GetLayerList();
	static Application* GetInstance();

protected:
	static Application* ApplicationInstance;

private:
	std::vector<std::unique_ptr<Layer>> m_LayerList;

};

Application* CreateApplication();





