#pragma once

namespace Core::ECS
{
	class ISparseSet
	{
	public:
		virtual ~ISparseSet() = default;
		virtual void RemoveComponentFromEntity(const std::uint32_t someEntityID) = 0;
		virtual std::vector<std::uint32_t>& GetSparseEntityArray() = 0;
		virtual std::vector<std::uint32_t>& GetDenseEntityArray() = 0;
	};
}

