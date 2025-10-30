#pragma once
#include "Core/Layer.h"

namespace IO::Input
{
    struct InputSystemPayload
    {
        InputSystemPayload(int someKeyPress) : KeyPressed(someKeyPress){}

        int KeyPressed = 0;
    };

    class InputSystem : public Core::Layer
    {
    public:
        InputSystem();
        ~InputSystem() override = default;

        void Update() override;
    };

    static InputSystem* InputSystemInstance = nullptr;
}
