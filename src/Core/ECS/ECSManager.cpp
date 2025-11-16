#include "Core/ECS/ECSManager.h"

#include <cassert>

#include "../../../include/Core/ECS/Systems/SystemBase.h"
#include "Core/ECS/Systems/MovementSystem.h"

static Core::ECS::ECSManager* ECSManagerInstance = nullptr;

Core::ECS::ECSManager::ECSManager(const std::uint32_t maxEntities) : m_maxEntities(maxEntities)
{
	if (ECSManagerInstance == nullptr)
	{
		ECSManagerInstance = this;
	}
}
