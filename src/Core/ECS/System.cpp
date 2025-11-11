#include "Core/ECS/System.h"

Core::ECS::System::System(const std::uint32_t entityCount) : m_entityCount(entityCount), m_SparseSet(entityCount){}

