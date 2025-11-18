#pragma once
#include <cstdint>
#include "SystemBase.h"
#include "Core/ECS/Components/Transform.h"

namespace Core::ECS::Systems
{
    class MovementSystem : public SystemBase<Components::Transform>
    {
    public:
        explicit MovementSystem(const std::uint32_t maxEntities);
        void BeginSystem() override;
        void UpdateSystem() override;
        void EndSystem() override;
    };
}
