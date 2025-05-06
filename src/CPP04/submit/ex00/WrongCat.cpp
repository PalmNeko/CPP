#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat(void)
    : WrongAnimal("WrongCat")
{
    std::clog << " + WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat& WrongCat)
    : WrongAnimal(WrongCat.type)
{
    std::clog << " @ Copy(WrongCat)" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::clog << " - WrongCat(" + this->getType() + ")" << std::endl;
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
    }
    return *this;
}
