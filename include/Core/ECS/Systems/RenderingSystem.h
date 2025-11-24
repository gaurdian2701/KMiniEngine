#pragma once
#include "Core/ECS/ECSManager.h"
#include "Assets/Components/Renderer2D.h"
#include "Assets/Components/Transform.h"
#include "System.h"

namespace Core::ECS::Systems
{
    class RenderingSystem : public System
    {
        RenderingSystem() = default;
        void BeginSystem() override;
        void UpdateSystem() override;
        void EndSystem() override;

    private:
        std::tuple<std::vector<Assets::Components::Transform>&, std::vector<Assets::Components::Renderer2D>&>
        m_interestedComponents = ECSManager::GetInstance()->QueryDenseComponentArrays<Assets::Components::Transform, Assets::Components::Renderer2D>();
    };
}
