#include "IO/FileSystem/FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

static IO::FileSystem::FileHandler* FileHandlerInstance = nullptr;

IO::FileSystem::FileHandler::FileHandler()
{
	if (FileHandlerInstance == nullptr)
	{
		FileHandlerInstance = this;
	}
	else
	{
		delete this;
	}
}

IO::FileSystem::FileHandler* IO::FileSystem::FileHandler::GetInstance()
{
	return FileHandlerInstance;
}

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