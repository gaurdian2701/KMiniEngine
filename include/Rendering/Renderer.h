#pragma once
#include "Shading/ShaderHandler.h"

namespace Rendering
{
	class Renderer
	{
	public:
		Renderer() = default;
		~Renderer() = default;

		Shading::ShaderHandler& GetShaderHandler();

	private:
		Shading::ShaderHandler m_shaderHandler;
	};
}
