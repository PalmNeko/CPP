#include "RPN.hpp"
#include <sstream>
#include <limits>
#include <stack>
#include <stdexcept>
#include <string>
#include <deque>

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
    {
    }
    return *this;
}

int RPN::rpn(const std::string &str)
{
	std::deque<char> instructions;
	std::stack<int> calc_space;

	std::string input;
	std::istringstream iss(str);
    while (iss >> input)
    {
		if (input.size() != 1)
			throw std::runtime_error("Bad length token");
        if (std::string("+-*/0123456789").find(input[0]) == std::string::npos)
            throw std::runtime_error("Bad character");
        if (std::string("0123456789").find(input[0]) != std::string::npos)
            calc_space.push(input[0] - '0');
        else if (std::string("+-*/").find(input[0]) != std::string::npos)
        {
            if (calc_space.size() < 2)
                throw std::runtime_error("Too many sign");
            int right = calc_space.top();
            calc_space.pop();
            int left = calc_space.top();
            calc_space.pop();
                int value = 0;
                if (input[0] == '+')
                    value = plus(left, right);
                else if (input[0] == '-')
                    value = minus(left, right);
                else if (input[0] == '*')
                    value = multiplies(left, right);
                else if (input[0] == '/')
                    value = divides(left, right);
                calc_space.push(value);
        }
    }
	if (calc_space.size() == 0)
		return (0);
    if (calc_space.size() >= 2)
        throw std::runtime_error("Too less sign");
    return (calc_space.top());
}

int RPN::plus(const int x, const int y)
{
    int intMax = std::numeric_limits<int>::max();
    int intMin = std::numeric_limits<int>::min();
    if ((y > 0) && (x > (intMax - y)))
        throw std::runtime_error("Overflow");
    if ((y < 0) && (x < (intMin - y)))
        throw std::runtime_error("Underflow");
    return x + y;
}

int RPN::minus(const int x, const int y)
{
    int intMax = std::numeric_limits<int>::max();
    int intMin = std::numeric_limits<int>::min();
    if ((y > 0) && (x < (intMin + y)))
	{
		throw std::runtime_error("Underflow");
	}
    if ((y < 0) && (x > (intMax + y)))
		throw std::runtime_error("Overflow");
    return x - y;
}

int RPN::multiplies(const int x, const int y)
{
	int intMax = std::numeric_limits<int>::max();
    int intMin = std::numeric_limits<int>::min();
    if (x > 0)
    {
        if (y > 0)
        {
            if (x > (intMax / y))
        		throw std::runtime_error("Overflow");
        }
        else
        {
            if (y < (intMin / x))
        		throw std::runtime_error("Underflow");
        }
    }
    else
    {
        if (y > 0)
        {
            if (x < (intMin / y))
        		throw std::runtime_error("Underflow");
        }
        else
        {
            if ((x != 0) && (y < (intMax / x)))
        		throw std::runtime_error("Overflow");
        }
    }
	return x * y;
}

int RPN::divides(const int x, const int y) {
    int intMin = std::numeric_limits<int>::min();
	if (y == 0)
		throw std::runtime_error("Division by zero");
	if ((y == 0) || ((x == intMin) && (y == -1)))
		throw std::runtime_error("Overflow");
	return x / y;
}
