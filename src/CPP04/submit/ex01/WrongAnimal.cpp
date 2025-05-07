#include "WrongAnimal.hpp"
#include <iostream>


WrongAnimal::WrongAnimal(void)
{
    std::cout << " + WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& WrongAnimal)
    : type(WrongAnimal.type)
{
    std::cout << " @ Copy(WrongAnimal)" << std::endl;
}
WrongAnimal::WrongAnimal(const std::string& type)
    : type(type)
{
    std::cout << " + WrongAnimal(" + type + ")" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << " - WrongAnimal(" + this->type + ")" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal makeSound." << std::endl;
}

const std::string& WrongAnimal::getType(void) const
{
    return (this->type);
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& WrongAnimal)
{
    if (this != &WrongAnimal)
    {
        this->type = WrongAnimal.type;
    }
    return *this;
}
