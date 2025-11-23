#include "IO/FileSystem/FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool IO::FileSystem::FileHandler::OpenFile(std::string& fileString, const std::string& filePath)
{
	std::ifstream ShaderFileStream;

	ShaderFileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	std::stringstream shaderStringStream;

	try
	{
		ShaderFileStream.open(filePath);
		shaderStringStream << ShaderFileStream.rdbuf();
		ShaderFileStream.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "FILE READING ERROR: " << e.what() << std::endl;
		return false;
	}

	fileString = shaderStringStream.str();
	return true;
}