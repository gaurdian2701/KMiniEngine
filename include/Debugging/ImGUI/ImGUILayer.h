#pragma once
#include "Core/Layer.h"

class ImGUILayer : public Layer
{
public:
	ImGUILayer() = default;
	~ImGUILayer() = default;

	void OnAttach() override;
	void Update() override;
	void Render() override;
	void OnDetach() override;
	void ProcessInput() override;
};
