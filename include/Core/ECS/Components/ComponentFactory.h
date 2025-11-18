#pragma once
#include <any>
#include <cassert>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>


namespace Core::ECS::Components
{
	class ComponentFactory
	{
	public:
		ComponentFactory() = default;
		~ComponentFactory() = default;

		template<typename T>
		void RegisterComponent()
		{
			m_componentMap[typeid(T)] = std::make_any<T>();
		}

		template<typename T>
		T CreateComponent()
		{
			std::any* storedComponent = &m_componentMap[typeid(T)];
			assert(storedComponent != nullptr);
			return std::any_cast<T>(*storedComponent);
		}

	private:
		std::unordered_map<std::type_index, std::any> m_componentMap;
	};
}
