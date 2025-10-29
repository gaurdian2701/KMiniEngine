#pragma once
#include <vector>
#include <memory>
#include <concepts>

namespace Core
{
	class Layer;
}

class Renderer;
class Window;

extern void UpdateApplication();

class Application
{
public:
	Application();
	virtual ~Application() = default;

	Application(const Application& other) = delete;

	void Init();
	void Run();

	static std::vector<std::unique_ptr<Core::Layer>>& GetLayerList();
	static Application* GetInstance();
	static Window* GetMainWindow();

	template<std::derived_from<Core::Layer> T, typename ... LayerArguments>
	void PushLayer(LayerArguments&& ... layerArguments)
	{
		LayerList.push_back(std::make_unique<T>(std::forward<LayerArguments>(layerArguments) ...));
	}

private:
	void PushLayers();
	void AttachAllLayers();
	void UpdateLayerList();
	void DetachAllLayers();
	void CloseGLFWWindow();
	void InitiateShutdown();

protected:
	static Application* ApplicationInstance;

private:
	static std::vector<std::unique_ptr<Core::Layer>> LayerList;
	static std::unique_ptr<Window> MainWindow;
};

Application* CreateApplication();





