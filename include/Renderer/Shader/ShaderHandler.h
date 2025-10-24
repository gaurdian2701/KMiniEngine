#pragma once
#include <unordered_map>
#include <string>
#include "Shader.h"

class FileHandler;

class ShaderHandler
{
public:
	ShaderHandler(FileHandler& fileHandler);
	Shader* GetShader(const std::string& filePath);

private:
	std::unordered_map<std::string, Shader*> m_shaderDictionary;

	void TryLoadShader(FileHandler& fileHandler, const std::string& filePath, SHADER_TYPE shaderType);
};