#pragma once
#include <vector>
#include "ECS/EntityManager.h"
#include "ECS/ComponentManager.h"

namespace Core
{
    namespace ECS
    {
        class Entity;
    }

    class Scene
    {
    public:
        Scene() = default;
        ~Scene() = default;

        ECS::Entity* CreateEntity();

        template<typename T, typename... ComponentArguments>
        void AddComponentToEntity(const std::uint32_t someEntityID, ComponentArguments&&... componentArguments)
        {
            m_componentManager.AddComponentToEntity<T>(someEntityID, componentArguments...);
        }

        template<typename T>
        void RemoveComponentFromEntity(const std::uint32_t someEntityID)
        {
            m_componentManager.RemoveComponentFromEntity<T>(someEntityID);
        }

    private:
        ECS::EntityManager m_entityManager;
        ECS::ComponentManager m_componentManager;
        std::vector<ECS::Entity*> m_entitiesInScene;
    };
}
