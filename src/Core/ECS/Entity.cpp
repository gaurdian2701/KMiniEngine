#include "Core/ECS/Entity.h"

Core::ECS::Entity::Entity(Scene* someScene, const std::uint32_t someEntityID)
{
    m_sceneReference = someScene;
    m_entityID = someEntityID;
}
