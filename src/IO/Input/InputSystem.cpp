#include "IO/Input/InputSystem.h"
#include <iostream>

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

void IO::Input::InputSystem::Update()
{
}
