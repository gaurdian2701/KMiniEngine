#include "Core/ECS/Systems/RenderingSystem.h"

#include <filesystem>

#include "glad/glad.h"
#include "IO/FileSystem/FileHandler.h"
#include "Rendering/Renderer.h"

void Core::ECS::Systems::RenderingSystem::BeginSystem()
{
    Rendering::Renderer::GetInstance()->GetShaderHandler().TryLoadShader(*IO::FileSystem::FileHandler::GetInstance(),
        std::filesystem::canonical(), )
}

void Core::ECS::Systems::RenderingSystem::UpdateSystem()
{
    auto& entities = ECSManager::GetInstance()->GetSmallestEntityArray<Assets::Components::Transform, Assets::Components::Renderer2D>();
    unsigned int VAO, VBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    for (auto& entity : entities)
    {
        auto& [transformComponentArray, renderer2DComponentArray] = m_interestedComponents;
    }
}

