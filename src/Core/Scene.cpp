#include "Core/Scene.h"
#include "Core/ECS/Entity.h"

Core::ECS::Entity* Core::Scene::CreateEntity()
{
    m_entitiesInScene.push_back(new ECS::Entity(this, m_entityManager.GetEntityID()));
    return m_entitiesInScene.back();
}
