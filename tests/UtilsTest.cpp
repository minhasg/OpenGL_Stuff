#include "Utils.h"
#include "UtilsTest.h"

#include <iostream>


bool utilsTest_readTextFromFileTest()
{
    std::cout << "Testing readTextFromFile." << std::endl;
    std::string data = readTextFromFile("./tests/testdata/textfile_test_1.txt");
    std::cout << data;
    std::string line1 = "This is some input text";
    std::string line2 = "This is the second line";
    std::string line3 = "These are numbers 123455";

    return true;
}
