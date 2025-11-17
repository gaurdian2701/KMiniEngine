#pragma once

namespace Core::ECS
{
	class ISparseSet
	{
	public:
		virtual void RemoveComponentFromEntity(const std::uint32_t someEntityID) = 0;
	};
}

