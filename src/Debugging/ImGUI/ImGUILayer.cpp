#include "Debugging/ImGUI/ImGUILayer.h"
#include "Application/Application.h"
#include "Application/Window.h"
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include "Core/StackSingletons.h"
#include "Core/Events/EventDatabase.h"
#include <iostream>

void Debugging::ImGUI::ImGUILayer::OnAttach()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& imguiIO = ImGui::GetIO();
    imguiIO.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    imguiIO.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui_ImplGlfw_InitForOpenGL(Application::GetMainWindow()->GetGLFWWindow(), true);
    ImGui_ImplOpenGL3_Init();

    GetEventSystem().SubscribeToEvent<Core::Events::Event_OnButtonPressed>(Core::Events::EventType::InputEvent,
        [this](const std::any& someEventPayload)
        {
            OnKeyPressed(someEventPayload);
        });
}

void Debugging::ImGUI::ImGUILayer::Update()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::ShowDemoWindow();
}

void Debugging::ImGUI::ImGUILayer::Render()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Debugging::ImGUI::ImGUILayer::OnDetach()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Debugging::ImGUI::ImGUILayer::OnKeyPressed(const std::any& someEventPayload)
{
    std::cout << "IMGUI EVENT LISTENER CALLED" << "\n";
}

void Debugging::ImGUI::ImGUILayer::ProcessInput()
{
    // if (glfwGetKey(Application::GetMainWindow()->GetGLFWWindow(), GLFW_KEY_I) == (GLFW_RELEASE | GLFW_PRESS))
    // {
    //     TransitionToLayer<Core::VoidLayer>();
    // }
}


