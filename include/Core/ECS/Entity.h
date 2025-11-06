#pragma once
#include <cstdint>
#include "Core/Scene.h"

namespace Core
{
    class Scene;
}

namespace Core::ECS
{
    class Entity
    {
    public:
        Entity(Scene* someScene, const std::uint32_t someEntityID);
        ~Entity() = default;

        template<typename T>
        void AddComponent()
        {
            m_sceneReference.AddComponentToEntity<T>(m_entityID);
        }

        template<typename T>
        void RemoveComponent()
        {
            m_sceneReference->RemoveComponentFromEntity<T>(m_entityID);
        }

    protected:
        Scene* m_sceneReference = nullptr;
        std::uint32_t m_entityID = -1;
    };
}
