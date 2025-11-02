#include "IO/Input/InputSystem.h"
#include <iostream>


static IO::Input::InputSystem* InputSystemInstance = nullptr;

IO::Input::InputSystem::InputSystem()
{
    if (InputSystemInstance != nullptr)
    {
        std::cout << "Input System already initialized!" << "\n";
    }
    else
    {
        InputSystemInstance = this;
    }
}

IO::Input::InputSystem *IO::Input::InputSystem::GetInstance()
{
    return InputSystemInstance;
}
