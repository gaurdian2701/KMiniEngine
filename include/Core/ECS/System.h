#pragma once
#include <cstdint>
#include <vector>

namespace Core::ECS
{
    template<typename ComponentTypeOwnedBySystem>
    class System
    {
    public:
        explicit System(const std::uint32_t entityCount) : m_entityCount(entityCount)
        {
            m_sparseEntityArray.resize(entityCount, -1);
            m_denseEntityArray.reserve(entityCount/2);
        }

        virtual ~System() = default;

        void AddComponentToEntity(const std::uint32_t entityID, ComponentTypeOwnedBySystem&& component)
        {
            m_denseEntityArray.push_back(entityID);
            m_denseComponentArray.push_back(std::forward<ComponentTypeOwnedBySystem>(component));

            if (m_sparseEntityArray.size()-1 < entityID)
            {
                m_sparseEntityArray.resize(entityID);
            }

            m_sparseEntityArray[entityID] = static_cast<std::uint32_t>(m_denseEntityArray.size()-1);
        }

        void RemoveComponentFromEntity(const std::uint32_t entityID)
        {
            const auto swappableLastEntityIndex = m_denseEntityArray.back();

            std::swap(m_denseEntityArray[m_sparseEntityArray[entityID]], m_denseEntityArray.back());
            std::swap(m_denseComponentArray[m_sparseEntityArray[entityID]], m_denseComponentArray.back());
            std::swap(m_sparseEntityArray[swappableLastEntityIndex], m_sparseEntityArray[entityID]);

            m_denseEntityArray.pop_back();
            m_denseComponentArray.pop_back();
            m_sparseEntityArray[entityID] = -1;
        }

        virtual void Update() = 0;

    protected:
        std::uint32_t m_entityCount = 0;

        std::vector<std::uint32_t> m_sparseEntityArray;
        std::vector<std::uint32_t> m_denseEntityArray;
        std::vector<ComponentTypeOwnedBySystem> m_denseComponentArray;
    };
}
