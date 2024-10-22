#include "Dog.hpp"
#include <iostream>

/*
 * special member functions
 */
Dog::Dog(void)
    : Animal("Dog")
{
    std::clog << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& dog)
    : Animal(dog.type)
{
    std::clog << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
    std::clog << "Dog destructor called" << std::endl;
}

/*
 * others: public
 */
void Dog::makeSound(void) const
{
    std::cout << "Bark" << std::endl;
}

/*
 * operators
 */

/*
 * others: private
 */
