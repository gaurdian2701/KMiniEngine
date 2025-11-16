#pragma once

namespace Core::ECS
{
    class ISystem
    {
    public:
        virtual void BeginSystem() = 0;
        virtual void UpdateSystem() = 0;
        virtual void EndSystem() = 0;
    };
}