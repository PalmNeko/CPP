#include "Animal.hpp"
#include <iostream>

/*
 * special member functions
 */
Animal::Animal(void)
{
    std::cout << " + Animal" << std::endl;
}

Animal::Animal(const Animal& animal)
    : type(animal.type)
{
    std::cout << " @ Copy(Animal)" << std::endl;
}
Animal::Animal(const std::string& type)
    : type(type)
{
    std::cout << " + Animal(" + type + ")" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << " - Animal(" + this->type + ")" << std::endl;
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
