#pragma once
#include "Layer.h"
#include "Application/Window.h"
#include "Debugging/ImGUI/ImGUILayer.h"
#include "GLFW/glfw3.h"

using namespace Debugging;

namespace Core
{
    class VoidLayer : public Layer
    {
    public:
        VoidLayer()
        {
        };

        ~VoidLayer() = default;

    protected:
        void ProcessInput() override
        {
            if (glfwGetKey(Application::GetInstance()->GetMainWindow()->GetGLFWWindow(), GLFW_KEY_I) == (GLFW_RELEASE | GLFW_PRESS))
            {
                TransitionToLayer<ImGUI::ImGUILayer>();
            }
        }
    };
}

