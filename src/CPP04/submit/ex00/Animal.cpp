#include "Animal.hpp"
#include <iostream>

/*
 * special member functions
 */
Animal::Animal(void)
{
    std::clog << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& animal)
    : type(animal.type)
{
    std::clog << "Animal copy constructor called" << std::endl;
}
Animal::Animal(const std::string& type)
    : type(type)
{
    std::clog << "Animal string constructor called" << std::endl;
}

Animal::~Animal(void)
{
    std::clog << "Animal destructor called" << std::endl;
}

/*
 * others: public
 */
void Animal::makeSound(void) const
{
    std::cout << "Animal makeSound" << std::endl;
}

const std::string& Animal::getType(void) const
{
    return this->type;
}

/*
 * operators
 */
Animal& Animal::operator=(const Animal& animal)
{
    if (this != &animal)
    {
        this->type = animal.type;
    }
    return *this;
}

/*
 * others: private
 */
