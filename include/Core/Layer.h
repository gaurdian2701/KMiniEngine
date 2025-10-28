#pragma once
#include <concepts>
#include "Application/Application.h"

class Layer
{
public:
	Layer() = default;
	virtual ~Layer() = default;

	virtual void OnAttach() {}
	virtual void OnDetach() {}
	virtual void ProcessInput(){}

	template<std::derived_from<Layer> T, typename ... LayerArguments>
	void TransitionToLayer(LayerArguments&& ... layerArguments)
	{
		std::unique_ptr<Layer> newLayer = std::make_unique<T>(std::forward<LayerArguments>(layerArguments) ...);

		for (int i = 0; i < Application::GetLayerList().size(); i++)
		{
			auto& currentLayer = Application::GetLayerList()[i];

			if (Application::GetLayerList()[i].get() == this)
			{
				currentLayer->OnDetach();
				currentLayer = std::move(newLayer);
				currentLayer->OnAttach();
			}
		}
	}

	virtual void Update() {}
	virtual void Render() {}
};