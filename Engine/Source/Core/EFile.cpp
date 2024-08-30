#include "..//../Source/Core/EFile.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <system_error>

namespace File
{
    static std::string filePath;

    std::string GetFilePath()
    {
       //return filePath;
        return std::filesystem::current_path().string();   
    }

    bool ReadFile(const std::string& filename, std::string& buffer)
    {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Could not open file: " << filename << std::endl;
            return false;
        }

        std::stringstream ss;
        ss << file.rdbuf();  // Read the file's content into a stringstream
        buffer = ss.str();   // Store the content in the provided buffer

        return true;
    }
    static bool FileExists(const std::string& filepath)
    {
        return std::filesystem::exists(filepath);
    }

    bool SetFilePath(const std::string& filepath)
    {
        
        if (FileExists(filepath)) {
            filePath = filepath;
            return true;
        }
        std::cerr << "File does not exist: " << filepath << std::endl;
        return false;

        std::error_code ec;
        std::filesystem::current_path(filepath, ec);

        if (ec) {
            std::cerr << "Could not set file path: " << ec.message() << std::endl;
        }

        return !ec;
    }
}
