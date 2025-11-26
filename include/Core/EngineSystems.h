#pragma once
#include "IO/FileSystem/FileHandler.h"
#include "Rendering/Renderer.h"
#include "Events/EventSystem.h"

namespace Core
{
	inline IO::FileSystem::FileHandler& GetFileHandler()
	{
		static IO::FileSystem::FileHandler MainFileHandler;
		return MainFileHandler;
	}

	inline Rendering::Renderer& GetRenderer()
	{
		static Rendering::Renderer MainRenderer;
		return MainRenderer;
	}

	inline Events::EventSystem& GetEventSystem()
	{
		static Events::EventSystem MainEventSystem;
		return MainEventSystem;
	}
}
