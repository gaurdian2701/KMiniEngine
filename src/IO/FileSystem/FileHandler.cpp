#include "FileHandler.h"
#include <fstream>
#include <sstream>

bool FileHandler::OpenShaderFile(std::string& shaderString, const std::string& shaderFilePath)
{
	std::ifstream ShaderFileStream;

	ShaderFileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	std::stringstream shaderStringStream;

	try
	{
		ShaderFileStream.open(shaderFilePath);
		shaderStringStream << ShaderFileStream.rdbuf();
		ShaderFileStream.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "FILE READING ERROR: " << e.what() << std::endl;
		return false;
	}

	shaderString = shaderStringStream.str();
	return true;
}