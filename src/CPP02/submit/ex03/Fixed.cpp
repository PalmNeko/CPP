#include "Fixed.hpp"
#include <iostream>
#include <ostream>
#include <cmath>

std::ostream* Fixed::o = &std::cout;

/*
 * special member functions
 */
Fixed::Fixed(void)
    : value(0)
{
    *Fixed::o << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
    : value(value << Fixed::fractionalBitNum)
{
    *Fixed::o << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
    : value(roundf(value * (1 << Fixed::fractionalBitNum)))
{
    *Fixed::o << "Float constructor called" << std::endl;
}


Fixed::Fixed(const Fixed& fixed)
    : value(fixed.value)
{
    *Fixed::o << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::~Fixed(void)
{
    *Fixed::o << "Destructor called" << std::endl;
}

/*
 * others: public
 */
int Fixed::getRawBits(void) const
{
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->value) / (1 << Fixed::fractionalBitNum));
}

#include <bitset>
int Fixed::toInt( void ) const
{
    return (this->value / (1 << Fixed::fractionalBitNum));
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b ? a : b);
}

void Fixed::setDebugStream(std::ostream& o)
{
    Fixed::o = &o;
}

/*
 * operators
 */
Fixed& Fixed::operator=(const Fixed& fixed)
{
    *Fixed::o << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
    {
        this->value = fixed.value;
    }
    return *this;
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (this->getRawBits() != fixed.getRawBits());
}


Fixed Fixed::operator+(const Fixed &fixed) const
{
    Fixed ret;
    ret.setRawBits(this->value + fixed.value);
    return (ret);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    Fixed ret;
    ret.setRawBits(this->value - fixed.value);
    return (ret);
}

int getSign(int a, int b)
{
    if (((a ^ b) & (1 << (sizeof(int) * 8 - 1))) == 0)
        return (1);
    else
        return (-1);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    int sign;
    unsigned int lhs, rhs;

    sign = getSign(this->getRawBits(), fixed.getRawBits());
    lhs = (this->getRawBits() < 0 ? -1 : 1) * this->getRawBits();
    rhs = (fixed.getRawBits() < 0 ? -1 : 1) * fixed.getRawBits();
    int fractionalSum = 0;
    int value = lhs;
    for (int i = Fixed::fractionalBitNum - 1; i >= 0; i--)
    {
        value >>= 1;
        fractionalSum += ((1 << i) & rhs) ? value : 0;
    }
    Fixed result;
    result.setRawBits(sign * (fractionalSum + (lhs * (rhs >> Fixed::fractionalBitNum))));
    return (result);
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    unsigned int rhs;
    unsigned int lhs;
    int sign;

    if (fixed.getRawBits() == 0)
        std::cout << (1 / fixed.getRawBits());
    sign = getSign(this->getRawBits(), fixed.getRawBits());
    lhs = (this->getRawBits() < 0 ? -1 : 1) * this->getRawBits();
    rhs = (fixed.getRawBits() < 0 ? -1 : 1) * fixed.getRawBits();
    unsigned int fractionalSum = 0;
    int value = lhs % rhs;

    for (int i = Fixed::fractionalBitNum - 1; i >= 0; i--)
    {
        value <<= 1;
        fractionalSum += (value / rhs) << i;
        value %= rhs;
    }
    int integerSum = 0;

    integerSum = (lhs / rhs) << Fixed::fractionalBitNum;
    Fixed result;
    result.setRawBits(sign * (fractionalSum + integerSum));
    return (result);
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed& Fixed::operator++(void)
{
    ++this->value;
    return (*this);
}

Fixed& Fixed::operator--(void)
{
    --this->value;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed ret(*this);
    ++*this;
    return (ret);
}

Fixed Fixed::operator--(int)
{
    Fixed ret(*this);
    --*this;
    return (ret);
}

#include <sstream>
void Fixed::output(std::ostream& o) const
{
    std::ostringstream oss;

    int integerPart = this->toInt();
    if (integerPart == 0 && this->getRawBits() < 0)
        oss << "-";
    int fractionalPart = this->value - (integerPart << Fixed::fractionalBitNum);
    float fractional = (float)fractionalPart / (1 << Fixed::fractionalBitNum);
    if (fractional < 0)
        fractional *= -1;
    std::string fractionalNum("");
    while (fractional != 0)
    {
        fractional *= 10;
        fractionalNum += ('0' + (int)fractional);
        fractional -= (int)fractional;
    }
    oss << integerPart;
    if (!fractionalNum.empty())
        oss << "." << fractionalNum;
    o << oss.str();
}

/**
 * others
 */
std::ostream& operator<<(std::ostream& o, const Fixed& rhs)
{
    rhs.output(o);
    return o;
}
