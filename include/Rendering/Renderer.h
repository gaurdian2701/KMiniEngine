#pragma once
#include "Shading/ShaderHandler.h"

namespace Rendering
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer() = default;

		static Renderer* GetInstance();

		Shading::ShaderHandler& GetShaderHandler();

	private:
		Shading::ShaderHandler m_shaderHandler;
	};
}
