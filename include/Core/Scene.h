#pragma once
#include <vector>
#include "Core/ECS/EntityManager.h"
#include "Core/ECS/ComponentManager.h"

namespace Core
{
    namespace ECS
    {
        class Entity;
        class EntityManager;
        class ComponentManager;
    }

    class Scene
    {
    public:
        Scene() = default;
        ~Scene() = default;

        ECS::Entity* CreateEntity();

        ECS::EntityManager* GetEntityManager();
        ECS::ComponentManager* GetComponentManager();

    private:
        ECS::EntityManager m_entityManager;
        ECS::ComponentManager m_componentManager;
        std::vector<ECS::Entity*> m_entitiesInScene;
    };
}
