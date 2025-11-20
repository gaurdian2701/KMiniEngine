#include "Core/GameScene.h"

#include "../../include/Assets/Components/Rigidbody.h"
#include "Scene/GameObject.h"
#include "../../include/Assets/Components/Transform.h"

Core::GameScene::GameScene(const std::uint32_t maxEntitiesInScene) : m_ECSManager(maxEntitiesInScene)
{
	m_gameObjectsInScene.reserve(maxEntitiesInScene);
	RegisterComponents();
	m_ECSManager.InitializeManager();
}

void Core::GameScene::RegisterComponents()
{
	m_ECSManager.RegisterComponent<Assets::Components::Transform>();
	m_ECSManager.RegisterComponent<Assets::Components::Rigidbody>();
}

void Core::GameScene::Update(const float deltaTime)
{
	UpdateGameObjects(deltaTime);
	UpdateECSManager();
}

void Core::GameScene::UpdateGameObjects(const float deltaTime)
{
	for (auto& gameObject : m_gameObjectsInScene)
	{
		gameObject->Update(deltaTime);
	}
}

void Core::GameScene::UpdateECSManager()
{
	m_ECSManager.UpdateManager();
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
