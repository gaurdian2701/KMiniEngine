#include "Core/ECS/EntityManager.h"

std::uint32_t Core::ECS::EntityManager::GetEntityID()
{
    static uint32_t entityID = 0;
    if (!m_entityFreeList.empty())
    {
        const uint32_t nextAvailableID = m_entityFreeList.back();
        m_entityFreeList.pop_back();
        return nextAvailableID;
    }
    return entityID++;
}

void Core::ECS::EntityManager::FreeEntity(const uint32_t someEntityID)
{
    m_entityFreeList.push_back(someEntityID);
}