#pragma once
#include <string>
#include <iostream>

namespace IO::FileSystem
{
	class FileHandler
	{
	public:
		static bool OpenShaderFile(std::string& shaderString, const std::string& shaderFilePath);
	};
}


