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

double RPN::rpn(const std::string &str)
{
	std::deque<char> instructions;
	std::stack<double> calc_space;

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
            double right = calc_space.top();
            calc_space.pop();
            double left = calc_space.top();
            calc_space.pop();
                double value = 0;
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

double RPN::plus(const double x, const double y)
{
    double doubleMax = std::numeric_limits<double>::max();
    double doubleMin = std::numeric_limits<double>::min();
    if ((y > 0) && (x > (doubleMax - y)))
        throw std::runtime_error("Overflow");
    if ((y < 0) && (x < (doubleMin - y)))
        throw std::runtime_error("Underflow");
    return x + y;
}

double RPN::minus(const double x, const double y)
{
    double doubleMax = std::numeric_limits<double>::max();
    double doubleMin = std::numeric_limits<double>::min();
    if ((y > 0) && (x < (doubleMin + y)))
	{
		throw std::runtime_error("Underflow");
	}
    if ((y < 0) && (x > (doubleMax + y)))
		throw std::runtime_error("Overflow");
    return x - y;
}

double RPN::multiplies(const double x, const double y)
{
	double doubleMax = std::numeric_limits<double>::max();
    double doubleMin = std::numeric_limits<double>::min();
    if (x > 0)
    {
        if (y > 0)
        {
            if (x > (doubleMax / y))
        		throw std::runtime_error("Overflow");
        }
        else
        {
            if (y < (doubleMin / x))
        		throw std::runtime_error("Underflow");
        }
    }
    else
    {
        if (y > 0)
        {
            if (x < (doubleMin / y))
        		throw std::runtime_error("Underflow");
        }
        else
        {
            if ((x != 0) && (y < (doubleMax / x)))
        		throw std::runtime_error("Overflow");
        }
    }
	return x * y;
}

double RPN::divides(const double x, const double y) {
    double doubleMin = std::numeric_limits<double>::min();
	if (y == 0)
		throw std::runtime_error("Division by zero");
	if ((y == 0) || ((x == doubleMin) && (y == -1)))
		throw std::runtime_error("Overflow");
	return x / y;
}
