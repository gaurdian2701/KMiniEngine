#pragma once
#include <cstdint>
#include <vector>

namespace Core::ECS
{
    class ComponentPool
    {
    public:
        ComponentPool(std::uint32_t maxEntities);
        ~ComponentPool() = default;

        //Rename and Refactor these functions later
        void AddEntity(const std::uint32_t entityID);
        void RemoveEntity(const std::uint32_t entityID);

    private:
        std::vector<std::uint32_t> m_sparseEntityArray;
        std::vector<std::uint32_t> m_denseEntityArray;
    };
}
