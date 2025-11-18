#pragma once
#include <bitset>

namespace Core::ECS::Components
{
	template <std::size_t someBitSetSize>
	class ComponentBitSet
	{
	public:
		std::bitset<someBitSetSize> m_bitSet;
	};
}
