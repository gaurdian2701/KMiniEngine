#include "Core/ECS/Systems/MovementSystem.h"

Core::ECS::Systems::MovementSystem::MovementSystem(const std::uint32_t maxEntities) : System(maxEntities) {}

void Core::ECS::Systems::MovementSystem::Update()
{
    for (uint32_t i = 0; i < m_denseComponentArray.size(); i++)
    {
        m_denseComponentArray[i].pos.x = 1;
    }
}

