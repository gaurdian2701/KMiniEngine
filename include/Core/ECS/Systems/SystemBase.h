#pragma once
#include "ISystem.h"
#include <tuple>
#include "Core/ECS/ECSManager.h"
#include "Core/ECS/SparseSet/SparseSet.h"

namespace Core::ECS::Systems
{
    template <typename FirstInterestedComponent, typename ... InterestedComponents>
    class SystemBase : public ISystem
    {
    public:
        explicit SystemBase(const std::uint32_t maxEntities) : m_maxEntities(maxEntities),
        m_interestedSparseSets(MakeComponentTuple(maxEntities))
        {}

        virtual ~SystemBase(){}

        virtual void BeginSystem() override {}
        virtual void UpdateSystem() override {}
        virtual void EndSystem() override {}

    private:
        auto MakeComponentTuple(std::uint32_t someMaxEntities)
        {
            return std::tuple(
                ECSManager::GetInstance()->GetComponentPool<FirstInterestedComponent>(),
                ECSManager::GetInstance()->GetComponentPool<InterestedComponents>() ...);
        }

    protected:
        std::uint32_t m_maxEntities = 0;
        std::tuple<SparseSet<FirstInterestedComponent>*, SparseSet<InterestedComponents>* ...> m_interestedSparseSets;
    };
}