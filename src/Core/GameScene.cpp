#include "Core/GameScene.h"
#include "Scene/GameObject.h"
#include "Core/ECS/Components/Transform.h"

Core::GameScene::GameScene(const std::uint32_t maxEntitiesInScene) : m_ECSManager(maxEntitiesInScene)
{
	m_gameObjectsInScene.reserve(maxEntitiesInScene);
	RegisterComponents();
}

void Core::GameScene::RegisterComponents()
{
	m_ECSManager.RegisterComponent<ECS::Components::Transform>();
}

void Core::GameScene::Update(const float deltaTime)
{
	for (auto& gameObject : m_gameObjectsInScene)
	{
		gameObject->Update(deltaTime);
	}
}

Core::ECS::ECSManager& Core::GameScene::GetECSManager()
{
	return m_ECSManager;
}

Scene::GameObject* Core::GameScene::CreateGameObject()
{
	m_gameObjectsInScene.push_back(new Scene::GameObject(m_ECSManager.GenerateEntityID(), this));
	return m_gameObjectsInScene.back();
}

void Core::GameScene::DeleteGameObject(Scene::GameObject* gameObject)
{
	m_ECSManager.FreeEntityID(gameObject->GetEntityID());
}
