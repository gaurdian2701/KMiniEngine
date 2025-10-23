#pragma once
#include <concepts>
#include "../Application/Application.h"

class Layer
{
public:
	Layer() = default;
	virtual ~Layer() = default;

	virtual void OnAttach() {}
	virtual void OnDetach() {}

	template<std::derived_from<Layer> T, typename ... LayerArguments>
	void TransitionToLayer(LayerArguments&& ... layerArguments)
	{
		auto newLayer = std::make_unique<T>(std::forward<LayerArguments>(layerArguments) ...);

		for (int i = 0; i < Application::GetInstance()->GetLayerList().size(); i++)
		{
			Layer* currentLayer =  Application::GetInstance()->GetLayerList()[i].get();

			if (Application::GetInstance()->GetLayerList()[i].get() == this)
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