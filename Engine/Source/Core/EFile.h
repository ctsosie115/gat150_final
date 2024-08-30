#pragma once
#include <string>
#include <iostream>


namespace File
{
	std::string GetFilePath();
	bool ReadFile(const std::string& filename, std::string& buffer);
	bool SetFilePath(const std::string& filepath);
}