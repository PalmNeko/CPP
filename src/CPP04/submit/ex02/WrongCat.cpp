#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat(void)
    : WrongAnimal("WrongCat")
{
    std::cout << " + WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat& WrongCat)
    : WrongAnimal(WrongCat.type)
{
    std::cout << " @ Copy(WrongCat)" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << " - WrongCat(" + this->getType() + ")" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "Roar" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& WrongCat)
{
    if (this != &WrongCat)
    {
        this->WrongAnimal::operator=(WrongCat);
        std::cout << " = WrongCat" << std::endl;
    }
    return *this;
}
