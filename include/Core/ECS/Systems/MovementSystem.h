#pragma once
#include <cstdint>
#include "System.h"

namespace Core::ECS::Systems
{
    class MovementSystem : public System
    {
    public:
        explicit MovementSystem(const std::uint32_t maxEntities);
        void BeginSystem() override;
        void UpdateSystem() override;
        void EndSystem() override;
    };
}
