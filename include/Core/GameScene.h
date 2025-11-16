#pragma once
#include "Core/ECS/ECSManager.h"

namespace Scene
{
    class GameObject;
}

namespace Core
{
    class GameScene
    {
    public:
        GameScene(const std::uint32_t maxEntitiesInScene);
        ~GameScene() = default;

        void Update(const float deltaTime);

        ECS::ECSManager& GetECSManager();

    private:
        ECS::ECSManager m_ECSManager;
        std::vector<Scene::GameObject*> m_gameObjectsInScene;
    };
}
