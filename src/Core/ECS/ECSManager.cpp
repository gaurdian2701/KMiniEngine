#include "Core/ECS/ECSManager.h"
#include "Core/ECS/Systems/MovementSystem.h"

static Core::ECS::ECSManager* ECSManagerInstance = nullptr;

Core::ECS::ECSManager::ECSManager(const std::uint32_t maxEntities) : m_maxEntities(maxEntities)
{
	if (ECSManagerInstance == nullptr)
	{
		ECSManagerInstance = this;
	}
}

Core::ECS::ECSManager* Core::ECS::ECSManager::GetInstance()
{
	return ECSManagerInstance;
}

void Core::ECS::ECSManager::CreateSystems()
{
	m_SystemsList.push_back(new Systems::MovementSystem(100));
}

std::uint32_t Core::ECS::ECSManager::GenerateEntityID()
{
	static std::uint32_t nextEntityID = 0;

	if (!m_entityFreeList.empty())
	{
		std::uint32_t entityID = m_entityFreeList.back();
		m_entityFreeList.pop_back();
		return entityID;
	}

	return nextEntityID++;
}

void Core::ECS::ECSManager::FreeEntityID(const std::uint32_t entityID)
{
	if (std::find(m_entityFreeList.begin(), m_entityFreeList.end(), entityID) == m_entityFreeList.end())
	{
		m_entityFreeList.push_back(entityID);
	}
}


