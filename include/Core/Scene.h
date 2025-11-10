#pragma once
#include <vector>


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

        // ECS::Entity* CreateEntity();

    private:
        std::vector<ECS::Entity*> m_entitiesInScene;
    };
}
