#pragma once
#include <cstdint>
#include <vector>

namespace Core::ECS
{
    class EntityManager
    {
    public:
        EntityManager() = default;
        ~EntityManager() = default;

        std::uint32_t GetEntityID();
        void FreeEntity(const uint32_t someEntityID);

    private:
        std::vector<uint32_t> m_entityFreeList;
    };
}
