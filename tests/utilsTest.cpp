#include "Utils.h"
#include <iostream>


bool readTextFromFileTest()
{
    std::cout << readTextFromFile("textfile_test_1.txt");
    return false;
}

void printResults()
{

}

int main()
{
    readTextFromFileTest();
    
    return 0;
}
