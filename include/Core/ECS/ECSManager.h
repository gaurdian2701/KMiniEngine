#pragma once
#include <typeindex>
#include <unordered_map>
#include <vector>
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
            std::uint32_t index = GetComponentIndex<T>();
            return *m_componentPools[index];
        }

        template<typename T>
        std::uint32_t RegisterComponent()
        {
            m_componentPools.push_back(new SparseSet<T>(m_maxEntities));
            return m_componentPools.size()-1;
        }

        template<typename T>
        std::uint32_t GetComponentIndex()
        {
            static std::uint32_t componentTypeIndex = GetInstance()->RegisterComponent<T>();
            return componentTypeIndex;
        }

        std::uint32_t GenerateEntityID();
        void FreeEntityID(const std::uint32_t entityID);

    private:
        void CreateSystems();

    private:
        std::uint32_t m_maxEntities = 0;

        std::vector<ISparseSet*> m_componentPools;
        std::vector<System*> m_SystemsList;
        std::vector<std::uint32_t> m_entityFreeList;
        std::unordered_map<std::type_index, System*> m_SystemsMap;
    };
}
