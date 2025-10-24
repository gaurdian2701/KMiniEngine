#pragma once
#include <vector>
#include <memory>
#include <concepts>

class Renderer;
class Window;
class Layer;

class Application
{
public:
	Application();
	virtual ~Application() = default;

	Application(const Application& other) = delete;

	virtual void Run();

	static std::vector<std::unique_ptr<Layer>>& GetLayerList();
	static Application* GetInstance();
	static Window* GetMainWindow();

	template<std::derived_from<Layer> T, typename ... LayerArguments>
	void PushLayer(LayerArguments&& ... layerArguments)
	{
		LayerList.push_back(std::make_unique<T>(std::forward<LayerArguments>(layerArguments) ...));
	}

protected:
	static Application* ApplicationInstance;

private:
	static std::vector<std::unique_ptr<Layer>> LayerList;
	static std::unique_ptr<Window> MainWindow;
};

Application* CreateApplication();





