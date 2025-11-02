#pragma once
#include "Core/Layer.h"

namespace IO::Input
{
    class InputSystem : public Core::Layer
    {
    public:
        InputSystem();
        ~InputSystem() override = default;

        static InputSystem* GetInstance();
    };


}
