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
		ShaderHandler(IO::FileSystem::FileHandler& fileHandler);
		Shader* GetShader(const std::string& filePath);

	private:
		std::unordered_map<std::string, Shader*> m_shaderDictionary;

		void TryLoadShader(IO::FileSystem::FileHandler& fileHandler, const std::string& filePath, SHADER_TYPE shaderType);
	};
}
