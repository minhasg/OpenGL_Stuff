#include <iostream>

#include "TestData.h" 

bool utilTest1()
{
    return true;
}

int main()
{
    TestData testVector;

    TestCase util_1("Function", 1, &utilTest1);

    testVector.run();
    testVector.printResults();

    return 0;
}
