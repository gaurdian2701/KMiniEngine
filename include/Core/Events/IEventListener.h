#pragma once
#include <any>

namespace Core::Events
{
    class IEventListener
    {
    public:
        IEventListener() = default;
        virtual ~IEventListener() = default;
        virtual void OnEventPublished(const std::any& somePayload) = 0;
    };
}
