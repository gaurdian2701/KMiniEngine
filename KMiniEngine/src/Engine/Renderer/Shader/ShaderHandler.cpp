#include "ShaderHandler.h"
#include "Config.h"
#include "../../FileHandling/FileHandler.h"
#include "Shader.h"

ShaderHandler::ShaderHandler(FileHandler& fileHandler)
{
	TryLoadShader(fileHandler, SIMPLE_OBJECT_VERTEX_SHADER_FILEPATH, SHADER_TYPE::VERTEX);
	TryLoadShader(fileHandler, SWAYING_OBJECT_VERTEX_SHADER_FILEPATH, SHADER_TYPE::VERTEX);

	TryLoadShader(fileHandler, SIMPLE_OBJECT_FRAGMENT_SHADER_FILEPATH, SHADER_TYPE::FRAGMENT);
	TryLoadShader(fileHandler, GRASS_RENDER_FRAGMENT_SHADER_FILEPATH, SHADER_TYPE::FRAGMENT);
}

void ShaderHandler::TryLoadShader(FileHandler& fileHandler, const std::string& filePath,
	SHADER_TYPE shaderType)
{
	std::string shaderString = "";

	assert(fileHandler.OpenShaderFile(shaderString, filePath));

	const char* shaderSource = shaderString.c_str();

	m_shaderDictionary[filePath] = 
		new Shader(shaderSource, shaderType);
}

Shader* ShaderHandler::GetShader(const std::string& filePath)
{
	if (m_shaderDictionary.find(filePath) == m_shaderDictionary.end())
	{
		return nullptr;
	}

	return m_shaderDictionary[filePath];
}
