#pragma once

namespace Core::ECS
{
    class System
    {
    public:
        explicit System(const std::uint32_t maxEntities) : m_maxEntities(maxEntities){}

        virtual void BeginSystem() = 0;
        virtual void UpdateSystem() = 0;
        virtual void EndSystem() = 0;

    protected:
        std::uint32_t m_maxEntities = 0;
    };
}