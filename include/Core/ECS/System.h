#pragma once
#include <cstdint>
#include "Resources/DataStructures/SparseSet.h"

namespace Core::ECS
{
    class System
    {

    public:
        explicit System(const std::uint32_t entityCount);
        virtual ~System() = default;

    protected:
        std::uint32_t m_entityCount = 0;
        Resources::DataStructures::SparseSet m_SparseSet;
    };
}
