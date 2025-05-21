#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

int genRandomNumber(void);

int main()
{
    std::cout << "=== basic ===" << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "=== random ===" << std::endl;

    const int randomValueSize = 60000;
    int randomValue[randomValueSize];
    std::generate_n(randomValue, randomValueSize, genRandomNumber);

    Span big = Span(randomValue, randomValue + randomValueSize);
    std::cout << big.shortestSpan() << std::endl;
    std::cout << big.longestSpan() << std::endl;

    std::cout << "=== error ===" << std::endl;

    try
    {
        big.addNumber(30);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}

int genRandomNumber(void)
{
    static bool isInitialized = false;
    if (isInitialized == false)
    {
        srand(static_cast<unsigned int>(time(NULL)));
        isInitialized = true;
    }
    return rand();
}
