#include <iostream>

#include "TestData.h" 
#include "UtilsTest.h"

int main()
{
    TestData testVector;

    TestCase util_1("readTextFromFile", 1, &utilsTest_readTextFromFileTest);

    testVector.addTestCase(util_1);
    testVector.run();
    testVector.printResults();

    return 0;
}
