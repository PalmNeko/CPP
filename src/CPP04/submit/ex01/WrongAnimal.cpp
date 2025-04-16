#include "WrongAnimal.hpp"
#include <iostream>

/*
 * special member functions
 */
WrongAnimal::WrongAnimal(void)
{
    std::clog << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& WrongAnimal)
    : type(WrongAnimal.type)
{
    std::clog << "WrongAnimal copy constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const std::string& type)
    : type(type)
{
    std::clog << "WrongAnimal string constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::clog << "WrongAnimal destructor called" << std::endl;
}

/*
 * others: public
 */
void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal makeSound." << std::endl;
}

/*
 * operators
 */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& WrongAnimal)
{
    if (this != &WrongAnimal)
    {
    }
    return *this;
}

/*
 * others: private
 */
