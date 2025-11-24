#pragma once
#include <string>

namespace IO::FileSystem
{
	class FileHandler
	{
	public:
		FileHandler();
		~FileHandler() = default;

		static FileHandler* GetInstance();

		static bool OpenFile(std::string& fileString, const std::string& filePath);
	};
}


