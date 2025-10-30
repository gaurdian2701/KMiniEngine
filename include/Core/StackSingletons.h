#pragma once
#include "Events/EventSystem.h"

static Core::Events::EventSystem& GetEventSystem()
{
    static Core::Events::EventSystem eventSystem;
    return eventSystem;
}
