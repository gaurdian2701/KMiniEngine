#pragma once
#include "../Core/Layer.h"

class Renderer : public Layer
{
public:
	Renderer();
	~Renderer();

	void OnAttach() override;
	void OnDetach() override;
	void Update() override;
};