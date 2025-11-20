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
        explicit GameScene(const std::uint32_t maxEntitiesInScene);
        ~GameScene() = default;

        void RegisterComponents();
        void Update(const float deltaTime);

        ECS::ECSManager& GetECSManager();

        Scene::GameObject* CreateGameObject();
        void DeleteGameObject(Scene::GameObject* gameObject);

    private:
        void UpdateGameObjects(const float deltaTime);
        void UpdateECSManager();

    private:
        ECS::ECSManager m_ECSManager;
        std::vector<Scene::GameObject*> m_gameObjectsInScene;
    };
}
