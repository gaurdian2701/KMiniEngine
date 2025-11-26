#include "Rendering/Shading/ShaderHandler.h"
#include "Rendering/Shading/Shader.h"
#include "IO/FileSystem/FileHandler.h"
#include <cassert>

void Rendering::Shading::ShaderHandler::TryLoadShader(const IO::FileSystem::FileHandler& fileHandler,
	const std::string& filePath,
	const SHADER_TYPE shaderType)
{
	std::string shaderString = "";

	assert(fileHandler.OpenFile(shaderString, filePath));

	const char* shaderSource = shaderString.c_str();

	m_shaderDictionary[filePath] = new Shader(shaderSource, shaderType);
}

Rendering::Shading::Shader* Rendering::Shading::ShaderHandler::GetShader(const std::string& filePath)
{
	if (!m_shaderDictionary.contains(filePath))
	{
		return nullptr;
	}
	return m_shaderDictionary[filePath];
}
