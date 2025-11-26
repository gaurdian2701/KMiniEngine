#pragma once
#include "glm/vec3.hpp"

namespace Assets::Components
{
    struct Renderer2D
    {
        //Default Constructor
        Renderer2D() = default;

        template<int ArraySize>
        Renderer2D(glm::vec3&& someColor, float (&someVertices)[ArraySize])
        {
            Color = someColor;
            vertices = std::vector<float>(someVertices, someVertices + ArraySize);
        }

        //Move Constructor
        Renderer2D(Renderer2D&& other) noexcept
        {
            Color = other.Color;
        }

        //Move Assignment Operator
        Renderer2D& operator=(Renderer2D&& other) noexcept
        {
            if (this != &other)
            {
                Color = other.Color;
            }

            return *this;
        }

        //Copy Constructor
        Renderer2D(const Renderer2D& other)
        {
            Color = other.Color;
        }

        glm::vec3 Color = glm::vec3(1.0f, 0.0f, 0.0f);
        std::vector<float> vertices;
    };
}