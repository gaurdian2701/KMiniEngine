#pragma once
#include <unordered_map>
#include <string>
#include "Shader.h"

namespace IO::FileSystem
{
	class FileHandler;
}

namespace Rendering::Shading
{
	class ShaderHandler
	{
	public:
		ShaderHandler() = default;
		Shader* GetShader(const std::string& filePath);

		void TryLoadShader(const IO::FileSystem::FileHandler& fileHandler,
		const std::string& filePath,
		const SHADER_TYPE shaderType);

	private:
		std::unordered_map<std::string, Shader*> m_shaderDictionary;


	};
}
