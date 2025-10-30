#pragma once

namespace Rendering::Shading
{
	enum class SHADER_TYPE
	{
		VERTEX,
		FRAGMENT
	};

	class Shader
	{
	public:
		Shader(const char* shaderSource, SHADER_TYPE shaderType);
		~Shader();
		unsigned int GetShaderID() const;

	private:
		virtual void TryShaderCompilation();

	private:
		unsigned int m_shaderID = 0;
		const char* m_shaderSource;
	};

}
