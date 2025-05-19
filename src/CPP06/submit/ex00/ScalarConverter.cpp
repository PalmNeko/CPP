#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
    // copy constructor
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
    if (this != &rhs)
    {
        // assignment logic
    }
    return *this;
}

void ScalarConverter::convert(const std::string &str)
{
    char charValue = 0;
    int intValue = 0;
    float floatValue = 0;
    double doubleValue = 0;

    bool isSuccessChar = false;
    bool isSuccessInt = false;
    bool isSuccessFloat = false;
    bool isSuccessDouble = false;

    // conversion
    { // double
        char *endptr = NULL;
        doubleValue = strtod(str.c_str(), &endptr);
        if (strcmp(endptr, "f") == 0)
        {
            if (isdigit(str[0]))
                isSuccessDouble = true;
            else if (strncmp("+inf", str.c_str(), 4) == 0
                     || strncmp("-inf", str.c_str(), 4) == 0
                     || strncmp("nan", str.c_str(), 3) == 0)
                isSuccessDouble = true;
            else
                isSuccessDouble = false;
        }
        else if (*endptr != '\0' || str[0] == '\0')
            isSuccessDouble = false;
        else
            isSuccessDouble = true;
    }
    { // float
        floatValue = static_cast<float>(doubleValue);
        isSuccessFloat = isSuccessDouble;
    }
    { // int
        long value;
        const int intMax = std::numeric_limits<int>::max();
        const int intMin = std::numeric_limits<int>::min();

        value = atol(str.c_str());
        intValue = static_cast<int>(value);
        if (value > intMax)
            intValue = intMax;
        else if (value < intMin)
            intValue = intMin;
        if (isSuccessDouble == false || value > intMax
            || value < intMin || std::isnan(floatValue) || std::isinf(floatValue) )
            isSuccessInt = false;
        else
            isSuccessInt = true;
    }
    {
        charValue = static_cast<char>(intValue);
        if (intValue > 255 || intValue < 0 || isSuccessInt == false)
            isSuccessChar = false;
        else
            isSuccessChar = true;
        if (isSuccessChar == false && str[0] != '\0' && str[1] == '\0')
        {
            charValue = str[0];
            isSuccessChar = true;
        }
    }

    // print
    std::cout << std::fixed << std::setprecision(1);
    {
        std::cout << "char: ";
        if (isSuccessChar == false)
            std::cout << "impossible";
        else if (isSuccessChar && ::isprint(charValue) == false)
            std::cout << "Non displayable";
        else
            std::cout << "'" << charValue << "'";
        std::cout << std::endl;

        std::cout << "int: ";
        if (isSuccessInt == false)
            std::cout << "impossible";
        else
            std::cout << intValue;
        std::cout << std::endl;

        std::cout << "float: ";
        if (isSuccessFloat == false)
            std::cout << "impossible";
        else
            std::cout << floatValue << "f";
        std::cout << std::endl;

        std::cout << "double: ";
        if (isSuccessDouble == false)
            std::cout << "impossible";
        else
            std::cout << doubleValue;
        std::cout << std::endl;
    }
    return;
}
