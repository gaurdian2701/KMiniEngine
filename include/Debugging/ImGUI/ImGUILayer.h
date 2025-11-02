#pragma once
#include <any>
#include "Core/Layer.h"

namespace Debugging::ImGUI
{
    class ImGUILayer : public Core::Layer
    {
    public:
        ImGUILayer() = default;
        ~ImGUILayer() override = default;

        void OnAttach() override;
        void Update() override;
        void Render() override;
        void OnDetach() override;

        //Toggle Layers on and off through GLFW Keypress callbacks
    };
}
