#pragma once
#include "Core/ECS/Component.h"

namespace Core::ECS::Components
{
    struct Transform : Component
    {
        struct Position
        {
            float x = 0.0f;
            float y = 0.0f;
            float z = 0.0f;
        };

        struct Rotation
        {
            float yaw = 0.0f;
            float pitch = 0.0f;
            float roll = 0.0f;
        };

        Position pos;
        Rotation rot;


    };
}
