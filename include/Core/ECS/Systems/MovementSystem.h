#pragma once
#include "Core/ECS/System.h"

namespace Core::ECS::Systems
{
    class MovementSystem : public System
    {
    public:
        MovementSystem(const std::uint32_t maxEntities);
    };
}
