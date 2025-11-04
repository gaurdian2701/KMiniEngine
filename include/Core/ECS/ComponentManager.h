#pragma once
#include <any>
#include <cstdint>
#include <typeindex>
#include <unordered_map>

namespace Core::ECS
{
    class ComponentManager
    {
    public:
        ComponentManager() = default;
        ~ComponentManager() = default;

        template<typename T>
        void RegisterComponent()
        {
            m_componentsInScene.insert_or_assign(std::type_index(typeid(T)), std::vector<std::any>{});
        }

        template<typename T, typename... ComponentArguments>
        void AddComponentToEntity(const std::uint32_t someEntityID, ComponentArguments&&... componentArguments)
        {
            auto& componentList = m_componentsInScene[std::type_index(typeid(T))];
            if (componentList.size()-1 < someEntityID)
            {
                componentList.resize(someEntityID);
            }
            else
            {
                componentList[someEntityID] = std::make_any<T>(componentArguments...);
            }
        }

        template<typename T>
        void RemoveComponentFromEntity(const std::uint32_t someEntityID)
        {
            auto& componentList = m_componentsInScene[std::type_index(typeid(T))];
            if (componentList.size()-1 >= someEntityID)
            {
                componentList[someEntityID].reset();
            }
        }

        template<typename T>
        void UnRegisterComponent()
        {
            m_componentsInScene.erase(std::type_index(typeid(T)));
        }

        template<typename T>
        T* GetComponentForEntity(const std::uint32_t someEntityID)
        {
            //TODO: This is unsafe, and I must change it later
            return &m_componentsInScene[std::type_index(typeid(T))][someEntityID];
        }

    private:
        std::unordered_map<std::type_index, std::vector<std::any>> m_componentsInScene;
    };
}
