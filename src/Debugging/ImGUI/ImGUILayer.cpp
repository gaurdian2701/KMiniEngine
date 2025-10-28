#include "Debugging/ImGUI/ImGUILayer.h"
#include "Application/Application.h"
#include "Application/Window.h"
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include "Core/VoidLayer.h"

void ImGUILayer::OnAttach()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& imguiIO = ImGui::GetIO();
    imguiIO.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    imguiIO.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui_ImplGlfw_InitForOpenGL(Application::GetMainWindow()->GetGLFWWindow(), true);
    ImGui_ImplOpenGL3_Init();
}

void ImGUILayer::Update()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::ShowDemoWindow();
}

void ImGUILayer::Render()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGUILayer::OnDetach()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGUILayer::ProcessInput()
{
    if (glfwGetKey(Application::GetMainWindow()->GetGLFWWindow(), GLFW_KEY_I) == (GLFW_RELEASE | GLFW_PRESS))
    {
        TransitionToLayer<VoidLayer>();
    }
}


