#pragma once
#include "Core/ECS/System.h"
#include "Core/ECS/Components/Transform.h"

namespace Core::ECS::Systems
{
    class MovementSystem : public System<Components::Transform>
    {
    public:
        explicit MovementSystem(const std::uint32_t maxEntities);
        void Update() override;
    };
}
