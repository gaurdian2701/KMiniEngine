#include "Core/ECS/Systems/MovementSystem.h"

Core::ECS::Systems::MovementSystem::MovementSystem(const std::uint32_t maxEntities) : SystemBase(maxEntities) {}

void Core::ECS::Systems::MovementSystem::BeginSystem(){}

void Core::ECS::Systems::MovementSystem::UpdateSystem()
{
    for (uint32_t i = 0; i < m_denseComponentArray.size(); i++)
    {
        m_denseComponentArray[i].pos.x = 1;
    }
}

void Core::ECS::Systems::MovementSystem::EndSystem(){}

