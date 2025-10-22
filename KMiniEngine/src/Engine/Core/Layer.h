#pragma once
#include <concepts>
#include "../Application/Application.h"

class Layer
{
public:
	Layer() = default;
	virtual void OnAttach() {}
	virtual void OnDetach() {}

	template<std::derived_from<Layer> T, typename ... LayerArguments>
	void TransitionToLayer(LayerArguments&& ... layerArguments)
	{
		auto newLayer = std::make_unique<T>(std::forward<LayerArguments>(layerArguments) ...);

		for (Layer* Layer : Application::GetInstance()->GetLayerList())
		{
			if (Layer == this)
			{
				Layer.OnDetach();
				Layer = std::move(newLayer);
				Layer->OnAttach();
			}
		}
	}

	virtual void Update() {}
	virtual void Render() {}
};