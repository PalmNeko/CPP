#include "Fixed.hpp"
#include "FixedTest.hpp"
#include <iostream>

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    FixedTest test;

    std::cout << std::endl;
    std::cout << "my test " << std::endl;
    try {
        test.testBinaryArithmeticOperators();
        test.testBinaryComparisonOperator();
        test.testUnaryOperator();
        test.testMin();
        test.testMax();
        std::cout << "done" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
