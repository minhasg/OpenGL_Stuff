#include "TestData.h"

#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const TestCase& obj)
{
    os << "Test case number " << obj._number << " of function " << obj._funcName << ": " << (obj._passed ? "PASSED" : "FAILED");
    return os;
}

TestCase::TestCase(std::string function, int caseNumber, bool (*testFunction)(void) )
{
    _funcName = function;
    _number = caseNumber;
    _testFunction = testFunction;
}

bool TestCase::run()
{
    _passed = _testFunction();
    return _passed;
}   

TestData::TestData()
{
    _testsRun = 0;
    _testsPassed = 0;
    _testCases = {};    
}

void TestData::printResults()
{
    std::cout << "Printing results for the test cases run: " << std::endl;
    for(int i = 0; i < (int) _testCases.size(); i++)
    {
        std::cout << _testCases[i] << std::endl;
    }

    std::cout << "Number of tests run: " << _testsRun << std::endl;
    std::cout << "Number of tests passed: " << _testsPassed << std::endl;
    std::cout << "Passing percentage: " << ( (float) _testsPassed / (float) _testsRun ) << "%" << std::endl;
}

void TestData::addTestCase(TestCase tc)
{
    _testCases.push_back(tc);
}

void TestData::run()
{
    for(int i = 0; i < (int) _testCases.size(); i++)
    {
        _testsPassed += _testCases[i].run() ? 1 : 0;
    }
    _testsRun = _testCases.size();
}

