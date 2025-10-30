#pragma once
#include "Core/Layer.h"

namespace IO::Input
{
    struct InputSystemPayload
    {
        InputSystemPayload(int someKeyPress) : KeyPressed(someKeyPress)
        {

        }
        int KeyPressed = 0;
    };

    class InputSystem : public Layer
    {
    public:
        InputSystem();
        ~InputSystem() override = default;

        void Update() override;
    };
}
