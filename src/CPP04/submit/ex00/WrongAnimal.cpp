#include "WrongAnimal.hpp"
#include <iostream>

/*
 * special member functions
 */
WrongAnimal::WrongAnimal(void)
{
    std::clog << " + WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& WrongAnimal)
    : type(WrongAnimal.type)
{
    std::clog << " @ Copy(WrongAnimal)" << std::endl;
}
WrongAnimal::WrongAnimal(const std::string& type)
    : type(type)
{
    std::clog << " + WrongAnimal(" + type + ")" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::clog << " - WrongAnimal(" + this->type + ")" << std::endl;
}

/*
 * others: public
 */
void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal makeSound." << std::endl;
}

const std::string& WrongAnimal::getType(void) const
{
    return (this->type);
}

/*
 * operators
 */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& WrongAnimal)
{
    if (this != &WrongAnimal)
    {
        this->type = WrongAnimal.type;
    }
    return *this;
}

/*
 * others: private
 */
