#pragma once
#include "Core/Layer.h"
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

class ImGUILayer : public Layer
{
public:

	void OnAttach() override;
};
