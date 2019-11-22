#include "Utils.h"

#include <iostream>
#include <fstream>
#include <sstream>

// Reads the contents of a file and returns the whole file in a single string
std::string readTextFromFile(std::string filename)
{
    std::string fileContents = "";
    std::ifstream file;

    std::string line = "";

    file.open(filename);
    while(std::getline(file, line))
    {
        fileContents += line;
    }

    return fileContents;
}
