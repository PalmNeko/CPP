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

/*
 * others: public
 */
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->value) / (1 << Fixed::fractionalBitNum));
}

int Fixed::toInt( void ) const
{
    return (this->value >> Fixed::fractionalBitNum);
}


/**
 * others
 */
std::ostream& operator<<(std::ostream& o, const Fixed& rhs)
{
    o << rhs.toFloat();
    return o;
}
