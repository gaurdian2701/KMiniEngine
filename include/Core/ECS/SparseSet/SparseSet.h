#pragma once
#include <cstdint>
#include <vector>
#include "ISparseSet.h"

namespace Core::ECS
{
	template<typename ComponentTypeUsedBySparseSet>
	class SparseSet : public ISparseSet
	{
	public:
		SparseSet(const std::uint32_t someMaxEntityCount) : m_maxEntityCount(someMaxEntityCount)
		{
			m_sparseEntityArray.resize(m_maxEntityCount, -1);
			m_denseEntityArray.reserve(m_maxEntityCount/2);
		}

		~SparseSet() = default;

		void AddComponentToEntity(const std::uint32_t entityID, ComponentTypeUsedBySparseSet&& component)
		{
			m_denseEntityArray.push_back(entityID);
			m_denseComponentArray.push_back(std::forward<ComponentTypeUsedBySparseSet>(component));

			if (m_sparseEntityArray.size()-1 < entityID)
			{
				m_sparseEntityArray.resize(entityID);
			}

			m_sparseEntityArray[entityID] = static_cast<std::uint32_t>(m_denseEntityArray.size()-1);
		}

		void RemoveComponentFromEntity(const std::uint32_t entityID) override
		{
			const auto swappableLastEntityIndex = m_denseEntityArray.back();

			std::swap(m_denseEntityArray[m_sparseEntityArray[entityID]], m_denseEntityArray.back());
			std::swap(m_denseComponentArray[m_sparseEntityArray[entityID]], m_denseComponentArray.back());
			std::swap(m_sparseEntityArray[swappableLastEntityIndex], m_sparseEntityArray[entityID]);

			m_denseEntityArray.pop_back();
			m_denseComponentArray.pop_back();
			m_sparseEntityArray[entityID] = -1;
		}

		std::vector<std::uint32_t>& GetSparseEntityArray() override
		{
			return m_sparseEntityArray;
		}

		std::vector<std::uint32_t>& GetDenseEntityArray() override
		{
			return m_denseEntityArray;
		}

		std::vector<ComponentTypeUsedBySparseSet>& GetDenseComponentArray()
		{
			return m_denseComponentArray;
		}

	private:
		std::uint32_t m_maxEntityCount;

		std::vector<std::uint32_t> m_sparseEntityArray;
		std::vector<std::uint32_t> m_denseEntityArray;
		std::vector<ComponentTypeUsedBySparseSet> m_denseComponentArray;
	};
}
