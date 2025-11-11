#pragma once
#include <vector>

namespace Core::ECS
{
    class System;

    class ECSManager
    {
    public:
        ECSManager();
        ~ECSManager() = default;

    private:
        void CreateSystems();

    private:
        std::vector<System> m_systemsList;
    };
}
