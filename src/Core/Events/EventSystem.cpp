#include "Core/Events/EventSystem.h"

#include <iostream>

static Core::Events::EventSystem* EventSystemInstance = nullptr;

Core::Events::EventSystem *Core::Events::EventSystem::GetInstance()
{
    return EventSystemInstance;
}

Core::Events::EventSystem::EventSystem()
{
    {
        if (EventSystemInstance != nullptr)
        {
            std::cout << "Event System Instance already exists!" << "\n";
        }
        else
        {
            EventSystemInstance = this;
        }
    }
}

