#pragma once
#include <any>
#include <typeindex>
#include <unordered_map>
#include "IEventListener.h"

namespace Core::Events
{
    inline struct EmptyPayload {} EmptyEventPayload;

    enum class EventType : uint16_t
    {
        InputEvent,
    };

    class EventSystem
    {
    public:
        EventSystem() = default;
        ~EventSystem() = default;

        template<typename T>
        void RegisterEvent(EventType someEventType)
        {
            auto& eventListenerMapForType = m_EventListenerTypeMap[someEventType];

            if (!eventListenerMapForType.contains(std::type_index(typeid(T))))
            {
                eventListenerMapForType.insert({std::type_index(typeid(T)), std::vector<IEventListener*>{}});
            }
        }

        template<typename T>
        void UnRegisterEvent(EventType someEventType)
        {
            auto& eventListenerMapForType = m_EventListenerTypeMap[someEventType];
            eventListenerMapForType.erase(std::type_index(typeid(T)));
        }

        template<typename T>
        void PublishEvent(EventType someEventType, const std::any& somePayload)
        {
            auto& eventListenerMapForType = m_EventListenerTypeMap[someEventType];
            auto& listenerList = eventListenerMapForType[std::type_index(typeid(T))];

            for (auto& listener : listenerList)
            {
                listener->OnEventPublished(somePayload);
            }
        }

        template<typename T>
        void SubscribeToEvent(EventType someEventType, IEventListener* someListener)
        {
            auto& eventListenerMapForType = m_EventListenerTypeMap[someEventType];
            auto& listenerList = eventListenerMapForType[std::type_index(typeid(T))];
            listenerList.push_back(someListener);
        }

        template<typename T>
        void UnsubscribeFromEvent(EventType someEventType, IEventListener* someListener)
        {
            auto& eventListenerMapForType = m_EventListenerTypeMap[someEventType];
            auto& listenerList = eventListenerMapForType[std::type_index(typeid(T))];
            const auto removeIterator = std::remove(listenerList.begin(), listenerList.end(), someListener);
            listenerList.erase(removeIterator, listenerList.end());
        }

    private:
        std::unordered_map<EventType, std::unordered_map<std::type_index, std::vector<IEventListener*>>> m_EventListenerTypeMap;
    };
}
