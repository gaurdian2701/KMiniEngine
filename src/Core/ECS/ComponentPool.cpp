#include "Core/ECS/ComponentPool.h"

Core::ECS::ComponentPool::ComponentPool(std::uint32_t maxEntities)
{
    m_sparseEntityArray.resize(maxEntities, -1);
    m_denseEntityArray.reserve(maxEntities/2);
}

void Core::ECS::ComponentPool::AddEntity(const std::uint32_t entityID)
{
    m_denseEntityArray.push_back(entityID);

    if (m_sparseEntityArray.size()-1 < entityID)
    {
        m_sparseEntityArray.resize(entityID);
    }

    m_sparseEntityArray[entityID] = static_cast<std::uint32_t>(m_denseEntityArray.size()-1);
}

void Core::ECS::ComponentPool::RemoveEntity(const std::uint32_t entityID)
{
    const auto swappableLastElement = m_denseEntityArray.back();
    std::swap(m_denseEntityArray[m_sparseEntityArray[entityID]], m_denseEntityArray.back());
    std::swap(m_sparseEntityArray[swappableLastElement], m_sparseEntityArray[entityID]);
    m_denseEntityArray.pop_back();
    m_sparseEntityArray[entityID] = -1;
}
