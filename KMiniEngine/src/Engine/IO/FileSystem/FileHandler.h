#pragma once
#include <string>
#include <iostream>

class FileHandler
{
public:
	static bool OpenShaderFile(std::string& shaderString, const std::string& shaderFilePath);
};

