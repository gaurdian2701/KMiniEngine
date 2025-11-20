#pragma once
#include <typeindex>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <iostream>
#include "Components/ComponentBitset.h"
#include "Components/ComponentFactory.h"
#include "SparseSet/SparseSet.h"

namespace Core::ECS
{
    class System;

    constexpr std::size_t MAX_COMPONENT_TYPES = 32;

    class ECSManager
    {
    public:
        explicit ECSManager(const std::uint32_t maxEntities);
        ~ECSManager() = default;
        void InitializeManager();
        void UpdateManager();

        static ECSManager* GetInstance();

        template <typename T>
        SparseSet<T>* GetComponentPool()
        {
            return static_cast<SparseSet<T>*>(m_componentPoolMap[std::type_index(typeid(T))]);
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
            ->AddComponentToEntity(someEntityID, std::forward<T>(m_ComponentFactory.CreateComponent<T>()));
        }

        template<typename T>
        void RemoveComponent(const std::uint32_t someEntityID)
        {
            dynamic_cast<SparseSet<T>*>(m_componentPoolMap[std::type_index(typeid(T))])
            ->RemoveComponentFromEntity(someEntityID);
        }

        template<typename T>
        T& GetComponent(std::uint32_t someEntityID)
        {
            return GetComponentPool<T>()->GetDenseComponentArray()[someEntityID];
        }

        template<typename FirstComponentType, typename ... ComponentType>
        std::vector<std::uint32_t>& GetSmallestEntityArray()
        {
            std::uint32_t smallestEntityArraySize = UINT32_MAX;
            std::type_index smallestEntityArrayTypeIndex = typeid(FirstComponentType);
            std::vector<std::uint32_t>* smallestEntityArray = &m_componentPoolMap[smallestEntityArrayTypeIndex]->GetDenseEntityArray();
            ([&]
            {
                auto& denseEntityArray = m_componentPoolMap[std::type_index(typeid(ComponentType))]->GetDenseEntityArray();
                if (int denseEntityArraySize = denseEntityArray.size(); denseEntityArraySize < smallestEntityArraySize)
                {
                    smallestEntityArraySize = denseEntityArraySize;
                    smallestEntityArrayTypeIndex = typeid(ComponentType);
                    smallestEntityArray = &denseEntityArray;
                }
            }(), ...);

            return *smallestEntityArray;
        }

        template<typename FirstComponentType, typename ... ComponentTypes>
        std::tuple<std::vector<FirstComponentType>&, std::vector<ComponentTypes>& ...> QueryDenseComponentArrays()
        {
            return std::forward_as_tuple(
                GetComponentPool<FirstComponentType>()->GetDenseComponentArray(),
                GetComponentPool<ComponentTypes>()->GetDenseComponentArray() ...);
        }

        static std::size_t GenerateIndex()
        {
            static std::size_t index = 0;
            return index++;
        }

        template<typename T>
        static std::size_t GetComponentTypeIndex()
        {
            static std::size_t componentTypeIndex = GenerateIndex();
            return componentTypeIndex;
        }

        std::uint32_t GenerateEntityID();
        void FreeEntityID(const std::uint32_t entityID);

    private:
        void InitializeSystems();

    private:
        std::uint32_t m_maxEntities = 0;

        std::vector<System*> m_SystemsList;
        std::vector<std::uint32_t> m_entityFreeList;
        std::unordered_map<std::type_index, ISparseSet*> m_componentPoolMap;
        Components::ComponentFactory m_ComponentFactory;
    };
}
