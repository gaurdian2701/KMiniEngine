#pragma once
#include <cstdint>
#include <vector>
#include "Core/ECS/ISystem.h"

namespace Core::ECS::Systems
{
    template<typename ComponentTypeOwnedBySystem>
    class SystemBase : public ISystem
    {
    public:
        SystemBase() = default;
        virtual ~SystemBase() = default;

        virtual void BeginSystem() override{}
        virtual void UpdateSystem() override{}
        virtual void EndSystem() override{}
    };
}
