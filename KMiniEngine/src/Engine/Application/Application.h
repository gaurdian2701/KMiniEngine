#pragma once
#include <vector>
#include <memory>
#include <concepts>

class Layer;

class Application
{
public:
	Application();
	virtual ~Application();
	Application(const Application& other) = delete;

	virtual void Run();

	std::vector<std::unique_ptr<Layer>>& GetLayerList();
	static Application* GetInstance();

	template<std::derived_from<Layer> T, typename ... LayerArguments>
	void PushLayer(LayerArguments&& ... layerArguments)
	{
		m_LayerList.push_back(std::make_unique<T>(std::forward<LayerArguments>(layerArguments) ...));
	}

protected:
	static Application* ApplicationInstance;

private:
	std::vector<std::unique_ptr<Layer>> m_LayerList;

};

Application* CreateApplication();





