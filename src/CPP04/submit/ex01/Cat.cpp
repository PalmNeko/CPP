#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

/*
 * special member functions
 */
Cat::Cat(void)
    : Animal("Cat")
{
    std::clog << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& cat)
    : Animal(cat.type)
{
    std::clog << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
    std::clog << "Cat destructor called" << std::endl;
}

/*
 * others: public
 */
void Cat::makeSound(void) const
{
    std::cout << "Miaow" << std::endl;
}

/*
 * operators
 */

/*
 * others: private
 */
