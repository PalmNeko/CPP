#include "FixedTest.hpp"

#include <iostream>

int main(void)
{
    FixedTest test;

    test.testBinaryArithmeticOperators();
    test.testBinaryComparisonOperator();
    test.testUnaryOperator();
    test.testMin();
    test.testMax();
    std::cout << "done" << std::endl;
    return (0);
}
