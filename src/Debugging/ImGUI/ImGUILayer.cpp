#include "Debugging/ImGUI/ImGUILayer.h"
#include "Application/Application.h"
#include "Application/Window.h"
#include "imgui/imgui.h"

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
