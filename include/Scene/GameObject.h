#pragma once
#include <cstdint>
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
        GameObject(std::uint32_t someEntityID, Core::GameScene* someSceneReference) : m_entityID(someEntityID), m_sceneReference(someSceneReference){}
        virtual ~GameObject();

        virtual void Update(const float deltaTime){}
        [[nodiscard]] std::uint32_t GetEntityID() const { return m_entityID;}

    private:
        std::uint32_t m_entityID = -1;
        Core::GameScene* m_sceneReference = nullptr;
    };
}
