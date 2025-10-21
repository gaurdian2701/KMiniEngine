#pragma once
#include <concepts>

class Layer
{
public:
	Layer() = default;
	virtual void OnAttach() {}
	virtual void OnDetach() {}

	template<std::derived_from<Layer> T, typename>
	void TransitionToLayer(T toLayer){}

	virtual void Update() {}
	virtual void Render() {}
};