#pragma once
#include <iostream>

namespace Core::ECS::Components
{
    struct Transform
    {
        //Default Constructor
        Transform()
        {
            std::cout << "Transform default constructor called \n";
        }

        //Move Constructor
        Transform(Transform&& other) noexcept
        {
            PositionVector = other.PositionVector;
            RotationVector = other.RotationVector;
        }

        //Move Assignment operator
        Transform& operator=(Transform&& other) noexcept
        {
            if (this != &other)
            {
                PositionVector = other.PositionVector;
                RotationVector = other.RotationVector;
            }
            return *this;
        }

        //Copy Constructor
        Transform(const Transform& other)
        {
            PositionVector = other.PositionVector;
            RotationVector = other.RotationVector;
        }

        struct Position
        {
            Position& operator=(const Position& other)
            {
                x = other.x;
                y = other.y;
                z = other.z;

                return *this;
            }

            float x = 0.0f;
            float y = 0.0f;
            float z = 0.0f;
        };

        struct Rotation
        {
            Rotation& operator=(const Rotation& other)
            {
                yaw = other.yaw;
                pitch = other.pitch;
                roll = other.roll;

                return *this;
            }

            float yaw = 0.0f;
            float pitch = 0.0f;
            float roll = 0.0f;
        };

        Position PositionVector;
        Rotation RotationVector;
    };
}
