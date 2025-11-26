#pragma once
#include <iostream>
#include <glm/mat4x4.hpp>
#include "glm/gtc/quaternion.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/quaternion.hpp"
#include "glm/ext/matrix_transform.hpp"

namespace Assets::Components
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
            ScaleVector = other.ScaleVector;
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

        glm::mat4 GetModelMatrix()
        {
            glm::mat4 translationMatrix = glm::mat4(1.0f);
            translationMatrix = glm::translate(translationMatrix, glm::vec3(PositionVector.x, PositionVector.y, PositionVector.z));
            glm::mat4 rotationMatrix = glm::mat4(1.0f);
            rotationMatrix = glm::toMat4(glm::quat(glm::vec3(RotationVector.x, RotationVector.y, RotationVector.z)));
            glm::mat4 scaleMatrix = glm::mat4(1.0f);
            scaleMatrix = glm::scale(scaleMatrix, glm::vec3(ScaleVector.x, ScaleVector.y, ScaleVector.z));

            return translationMatrix * rotationMatrix * scaleMatrix;
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
                x = other.x;
                y = other.y;
                z = other.z;

                return *this;
            }

            float x = 0.0f;
            float y = 0.0f;
            float z = 0.0f;
        };

        struct Scale
        {
            Scale&  operator=(const Scale& other)
            {
                x = other.x;
                y = other.y;
                z = other.z;

                return *this;
            }

            float x = 1.0f;
            float y = 1.0f;
            float z = 1.0f;
        };

        Position PositionVector;
        Rotation RotationVector;
        Scale ScaleVector;
    };
}
