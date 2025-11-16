#include "Scene/GameObject.h"

Scene::GameObject::GameObject(std::uint32_t someEntityID, Core::GameScene* someSceneReference)
: m_entityID(someEntityID), m_sceneReference(someSceneReference) {}
