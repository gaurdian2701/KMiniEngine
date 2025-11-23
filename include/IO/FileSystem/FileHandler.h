#pragma once
#include <string>

namespace IO::FileSystem
{
	class FileHandler
	{
	public:
		FileHandler() = default;
		~FileHandler() = default;

		static bool OpenFile(std::string& fileString, const std::string& filePath);
	};
}


