#pragma once
#include <typeindex>
#include <unordered_map>
#include <vector>
#include "Components/ComponentFactory.h"
#include "SparseSet/SparseSet.h"

namespace Core::ECS
{
    class System;

    class ECSManager
    {
    public:
        explicit ECSManager(const std::uint32_t maxEntities);
        ~ECSManager() = default;

        static ECSManager* GetInstance();

        template <typename T>
        ISparseSet& GetComponentPool()
        {
            return *m_componentPoolMap[std::type_index(typeid(T))];
        }

        template<typename T>
        void RegisterComponent()
        {
            m_ComponentFactory.RegisterComponent<T>();
            m_componentPoolMap[std::type_index(typeid(T))] = new SparseSet<T>(m_maxEntities);
        }

        template<typename T>
        void AddComponent(const std::uint32_t someEntityID)
        {
            dynamic_cast<SparseSet<T>*>(m_componentPoolMap[std::type_index(typeid(T))])
            ->AddComponentToEntity(someEntityID, m_ComponentFactory.CreateComponent<T>());
        }

        template<typename T>
        void RemoveComponent(const std::uint32_t someEntityID)
        {
            dynamic_cast<SparseSet<T>*>(m_componentPoolMap[std::type_index(typeid(T))])
            ->RemoveComponentFromEntity(someEntityID);
        }

        std::uint32_t GenerateEntityID();
        void FreeEntityID(const std::uint32_t entityID);

    private:
        void CreateSystems();

    private:
        std::uint32_t m_maxEntities = 0;

        std::vector<System*> m_SystemsList;
        std::vector<std::uint32_t> m_entityFreeList;
        std::unordered_map<std::type_index, ISparseSet*> m_componentPoolMap;

        Components::ComponentFactory m_ComponentFactory;
    };
}
