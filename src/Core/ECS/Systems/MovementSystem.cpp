#include "Core/ECS/Systems/MovementSystem.h"
#include "Core/ECS/ECSManager.h"
#include "Assets/Components/Transform.h"

void Core::ECS::Systems::MovementSystem::BeginSystem()
{
}

void Core::ECS::Systems::MovementSystem::UpdateSystem()
{
	auto& entities = ECSManager::GetInstance()->GetSmallestEntityArray<Assets::Components::Transform>();

	for (auto& entity : entities)
	{
		auto& [transformComponentArray] = m_interestedComponents;
		transformComponentArray[entity].PositionVector.x = 1;
	}
}

void Core::ECS::Systems::MovementSystem::EndSystem()
{

}

