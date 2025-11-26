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

extern void BeginApplication();
extern void UpdateApplication(const float deltaTime);
extern void EndApplication();

class Application
{
public:
	Application();
	virtual ~Application();
	Application(const Application& other) = delete;

	static Application* GetInstance();

	void Init();
	void Run();

	std::vector<std::unique_ptr<Core::Layer>>& GetLayerList();
	Window* GetMainWindow();

	template<std::derived_from<Core::Layer> T, typename ... LayerArguments>
	void PushLayer(LayerArguments&& ... layerArguments)
	{
		LayerList.push_back(std::make_unique<T>(std::forward<LayerArguments>(layerArguments) ...));
	}

private:
	void PushLayers();
	void AttachAllLayers() const;
	void UpdateLayerList();
	void DetachAllLayers();
	void CloseGLFWWindow();
	void InitiateShutdown();

protected:
	static Application* ApplicationInstance;

private:
	std::vector<std::unique_ptr<Core::Layer>> LayerList;
};

Application& CreateApplication();





