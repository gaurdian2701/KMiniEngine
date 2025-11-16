#pragma once
#include <cstdint>
#include <concepts>
#include "Core/ECS/Component.h"
#include "Core/GameScene.h"

namespace Core
{
    class GameScene;
}

namespace Scene
{
    class GameObject
    {
    public:
        GameObject(std::uint32_t someEntityID, Core::GameScene* someSceneReference);
        ~GameObject();

        virtual void Update(const float deltaTime){}

    private:
        std::uint32_t m_entityID = -1;
        Core::GameScene* m_sceneReference = nullptr;
    };
}
