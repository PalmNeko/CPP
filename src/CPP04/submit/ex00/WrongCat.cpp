#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

/*
 * special member functions
 */
WrongCat::WrongCat(void)
    : WrongAnimal("WrongCat")
{
    std::clog << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& WrongCat)
    : WrongAnimal(WrongCat.type)
{
    std::clog << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::clog << "WrongCat destructor called" << std::endl;
}

/*
 * others: public
 */
void WrongCat::makeSound(void) const
{
    std::cout << "Roar" << std::endl;
}

/*
 * operators
 */

/*
 * others: private
 */
