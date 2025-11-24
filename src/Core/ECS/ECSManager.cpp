#include "Core/ECS/ECSManager.h"
#include "Core/ECS/Systems/MovementSystem.h"

static Core::ECS::ECSManager* ECSManagerInstance = nullptr;

Core::ECS::ECSManager::ECSManager(const std::uint32_t maxEntities) : m_maxEntities(maxEntities)
{
	if (ECSManagerInstance == nullptr)
	{
		ECSManagerInstance = this;
	}
	else
	{
		delete this;
	}
}

void Core::ECS::ECSManager::InitializeManager()
{
	InitializeSystems();
}

void Core::ECS::ECSManager::InitializeSystems()
{
	m_SystemsList.push_back(new Systems::MovementSystem());
	m_SystemsList[0]->BeginSystem();
}

Core::ECS::ECSManager* Core::ECS::ECSManager::GetInstance()
{
	return ECSManagerInstance;
}

void Core::ECS::ECSManager::UpdateManager()
{
	for (auto& system : m_SystemsList)
	{
		system->UpdateSystem();
	}
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


