#include "Rendering/Renderer.h"

static Rendering::Renderer* RendererInstance = nullptr;

Rendering::Renderer::Renderer()
{
    if (RendererInstance == nullptr)
    {
        RendererInstance = this;
    }
    else
    {
        delete this;
    }
}

Rendering::Renderer* Rendering::Renderer::GetInstance()
{
    return RendererInstance;
}

Rendering::Shading::ShaderHandler& Rendering::Renderer::GetShaderHandler()
{
    return m_shaderHandler;
}
