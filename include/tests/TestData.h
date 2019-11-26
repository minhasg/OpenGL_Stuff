#ifndef _TEST_DATA_H_
#define _TEST_DATA_H_

#include <iostream>
#include <ostream>
#include <vector>

class TestCase
{
    private:
        std::string _funcName;
        int _number;
        bool _passed;
        bool (*_testFunction)(void);
    public:
        TestCase(std::string, int, bool (*testFunction)(void));
        bool run();
        friend std::ostream& operator<<(std::ostream& os, const TestCase& obj);
};

class TestData
{
    public:
        TestData();
        void printResults();
        void addTestCase(TestCase tc);
        void run(); 

    protected:
        int _testsRun;
        int _testsPassed;
        std::vector<TestCase> _testCases;
};


#endif
