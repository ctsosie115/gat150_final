#include "EString.h"

std::string ToLower(const std::string& str)
{
    std::string lower;
    lower.resize(str.size());


    //modern C++ code
    std::transform(str.begin(), str.end(), lower.begin(),
        [](auto c)
        {
            return std::tolower(c); 
        });

    return lower;

    //for (int i = 0; i < lower.size(); i++) {
    //    lower[i] = std::tolower(str[i]);
    //}

    /*for (auto c : str) {
        
        lower.push_back(std::toLower(c));
    }
    return lower;*/
}

std::string ToUpper(const std::string& str)
{
    std::string upper;
    upper.resize(str.size());

    //modern C++ code
    std::transform(str.begin(), str.end(), upper.begin(),
        [](auto c)
        {
            return std::toupper(c);
        });

    return upper;
}

bool IsEqualIgonreCase(const std::string& str1, const std::string& str2)
{
    if (str1.length() != str2.length()) { return false;}

    bool sucess = std::equal(str1.begin(), str1.end(), str2.begin(),
    [](char c1, char c2)
        {
            return std::tolower(c1) == std::tolower(c2);
        });

    return sucess;
}
