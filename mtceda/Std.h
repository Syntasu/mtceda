#ifndef STD_H
#define STD_H

#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <string>

inline std::vector<std::string> split(std::string str, char delimiter)
{
    std::stringstream ss(str);
    std::vector<std::string> result;

    while (ss.good())
    {
        std::string substr;
        getline(ss, substr, delimiter);
        result.push_back(substr);
    }

    return result;
}

#endif