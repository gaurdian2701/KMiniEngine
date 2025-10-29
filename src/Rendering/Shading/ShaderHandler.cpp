#include "Rendering/Shading/ShaderHandler.h"
#include "Rendering/Shading/Shader.h"
#include "Rendering/RenderConfigs.h"
#include "IO/FileSystem/FileHandler.h"

Rendering::Shading::ShaderHandler::ShaderHandler(IO::FileSystem::FileHandler& fileHandler)
{
	TryLoadShader(fileHandler, SIMPLE_OBJECT_VERTEX_SHADER_FILEPATH, SHADER_TYPE::VERTEX);
	TryLoadShader(fileHandler, SWAYING_OBJECT_VERTEX_SHADER_FILEPATH, SHADER_TYPE::VERTEX);

	TryLoadShader(fileHandler, SIMPLE_OBJECT_FRAGMENT_SHADER_FILEPATH, SHADER_TYPE::FRAGMENT);
	TryLoadShader(fileHandler, GRASS_RENDER_FRAGMENT_SHADER_FILEPATH, SHADER_TYPE::FRAGMENT);
}

void Rendering::Shading::ShaderHandler::TryLoadShader(IO::FileSystem::FileHandler& fileHandler, const std::string& filePath,
                                                      SHADER_TYPE shaderType)
{
	std::string shaderString = "";

	assert(fileHandler.OpenShaderFile(shaderString, filePath));

	const char* shaderSource = shaderString.c_str();

	m_shaderDictionary[filePath] = 
		new Shader(shaderSource, shaderType);
}

Rendering::Shading::Shader* Rendering::Shading::ShaderHandler::GetShader(const std::string& filePath)
{
	if (m_shaderDictionary.find(filePath) == m_shaderDictionary.end())
	{
		return nullptr;
	}

	return m_shaderDictionary[filePath];
}
