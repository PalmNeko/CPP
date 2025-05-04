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
    return (static_cast<float>(this->getRawBits()) / (1 << Fixed::fractionalBitNum));
}

int Fixed::toInt( void ) const
{
    return (this->getRawBits() >> Fixed::fractionalBitNum);
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
        this->setRawBits(fixed.getRawBits());
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
    ret.setRawBits(this->getRawBits() + fixed.getRawBits());
    return (ret);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    Fixed ret;
    ret.setRawBits(this->getRawBits() - fixed.getRawBits());
    return (ret);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed& Fixed::operator++(void)
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed& Fixed::operator--(void)
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed ret(*this);
    this->setRawBits(this->getRawBits() + 1);
    return (ret);
}

Fixed Fixed::operator--(int)
{
    Fixed ret(*this);
    this->setRawBits(this->getRawBits() - 1);
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
