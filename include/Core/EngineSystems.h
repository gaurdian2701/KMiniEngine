#pragma once
#include "IO/FileSystem/FileHandler.h"
#include "Rendering/Renderer.h"
#include "Events/EventSystem.h"

namespace Core
{
	inline auto MainFileHandler = IO::FileSystem::FileHandler();
	inline auto MainRenderer = Rendering::Renderer();
	inline auto MainEventSystem = new Events::EventSystem();
}
