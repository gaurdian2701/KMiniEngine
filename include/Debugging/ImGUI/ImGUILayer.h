#pragma once
#include "Core/Layer.h"

class ImGUILayer : public Layer
{
public:

	void OnAttach() override;
	void Update() override;
	void Render() override;
	void OnDetach() override;
};
