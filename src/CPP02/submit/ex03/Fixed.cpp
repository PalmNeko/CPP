#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/*
 * special member functions
 */
Fixed::Fixed(void)
    : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
    : value(value << Fixed::fractionalBitNum)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
    : value(roundf(value * (1 << Fixed::fractionalBitNum)))
{
    std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
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
    return ((float)(this->value) / (1 << Fixed::fractionalBitNum));
}

int Fixed::toInt( void ) const
{
    return (this->value >> Fixed::fractionalBitNum);
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

/*
 * operators
 */
Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
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

Fixed Fixed::operator*(const Fixed &fixed) const
{
    int fractionalSum = 0;
    int value = this->getRawBits();

    for (int i = Fixed::fractionalBitNum - 1; i >= 0; i--)
    {
        value >>= 1;
        fractionalSum += ((1 << i) & fixed.getRawBits()) ? value : 0;
    }
    Fixed result;
    result.setRawBits(fractionalSum + (this->getRawBits() * fixed.toInt()));
    return (result);
    // return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    int fractionalSum = 0;
    int value = this->getRawBits();

    if (fixed.getRawBits() == 0)
        std::cout << (1 / fixed.getRawBits());
    for (int i = Fixed::fractionalBitNum - 1; i >= 0; i--)
    {
        value <<= 1;
        fractionalSum += ((1 << i) & fixed.getRawBits()) ? value : 0;
    }
    int integerSum = 0;
    if (fixed.toInt() != 0)
        integerSum = (this->getRawBits() / fixed.toInt());
    Fixed result;
    result.setRawBits(fractionalSum + integerSum);
    return (result);
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

/**
 * others
 */
std::ostream& operator<<(std::ostream& o, const Fixed& rhs)
{
    o << rhs.toFloat();
    return o;
}
