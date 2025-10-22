#pragma once
#include "../../Core/Layer.h"
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

class ImGUILayer : public Layer
{
	void OnAttach()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& imguiIO = ImGui::GetIO();
		imguiIO.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		imguiIO.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

		//ImGui_ImplGlfw_InitForOpenGL(window, true);
		//ImGui_ImplOpenGL3_Init();
	}
};
