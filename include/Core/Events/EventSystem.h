#pragma once
#include <any>
#include <cstdint>
#include <typeindex>
#include <unordered_map>
#include <functional>

namespace Core::Events
{
    struct ListenerFunctionData
    {
        ListenerFunctionData(const std::function<void(const std::any&)>& someListenerFunction, const std::uint32_t someFunctionID)
        {
            ListenerFunction = someListenerFunction;
            functionID = someFunctionID;
        }

        bool operator==(const ListenerFunctionData& other)
        {
           return functionID = other.functionID;
        }

        std::function<void(const std::any&)> ListenerFunction;
        uint32_t functionID = 0;
    };

    enum class EventType : uint16_t
    {
        InputEvent,
    };

    class EventSystem
    {
    public:
        EventSystem();
        ~EventSystem() = default;

        static EventSystem* GetInstance();

        template<typename T>
        void RegisterEvent(const EventType someEventType)
        {
            auto& eventListenerMapForType = m_EventListenerTypeMap[someEventType];

            if (!eventListenerMapForType.contains(std::type_index(typeid(T))))
            {
                eventListenerMapForType.insert({std::type_index(typeid(T)), std::vector<ListenerFunctionData>{}});
            }
        }

        template<typename T>
        void UnRegisterEvent(const EventType someEventType)
        {
            auto& eventListenerMapForType = m_EventListenerTypeMap[someEventType];
            eventListenerMapForType.erase(std::type_index(typeid(T)));
        }

        template<typename T>
        void PublishEvent(const EventType someEventType, const std::any& somePayload)
        {
            auto& eventListenerMapForType = m_EventListenerTypeMap[someEventType];
            auto& listenerList = eventListenerMapForType[std::type_index(typeid(T))];

            for (auto& listener : listenerList)
            {
                listener.ListenerFunction(somePayload);
            }
        }

        template<typename T>
        uint32_t SubscribeToEvent(const EventType someEventType, std::function<void(const std::any&)> someListenerFunction)
        {
            static uint32_t functionListenerID = 0;
            auto& eventListenerMapForType = m_EventListenerTypeMap[someEventType];
            auto& listenerList = eventListenerMapForType[std::type_index(typeid(T))];
            listenerList.emplace_back(someListenerFunction, functionListenerID);
            return functionListenerID++;
        }

        template<typename T>
        void UnsubscribeFromEvent(const EventType someEventType, const uint32_t someFunctionID)
        {
            auto& eventListenerMapForType = m_EventListenerTypeMap[someEventType];
            auto& listenerList = eventListenerMapForType[std::type_index(typeid(T))];
            auto removeIterator = std::remove_if(listenerList.begin(), listenerList.end(),
                [&](const ListenerFunctionData& listenerFunctionData)
                {
                    return listenerFunctionData.functionID == someFunctionID;
                });
            listenerList.erase(removeIterator, listenerList.end());
        }

    private:
        std::unordered_map<EventType, std::unordered_map<std::type_index, std::vector<ListenerFunctionData>>> m_EventListenerTypeMap;
    };
}
