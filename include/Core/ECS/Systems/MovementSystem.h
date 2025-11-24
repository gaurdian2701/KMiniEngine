#pragma once
#include "Core/ECS/ECSManager.h"
#include "Assets/Components/Transform.h"
#include "System.h"


namespace Core::ECS::Systems
{
    class MovementSystem : public System
    {
    public:
        MovementSystem() = default;
        void BeginSystem() override;
        void UpdateSystem() override;
        void EndSystem() override;

    private:
        std::tuple<std::vector<Assets::Components::Transform>&> m_interestedComponents =
            ECSManager::GetInstance()->QueryDenseComponentArrays<Assets::Components::Transform>();
    };
}
