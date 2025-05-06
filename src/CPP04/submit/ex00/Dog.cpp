#include "Dog.hpp"
#include <iostream>

/*
 * special member functions
 */
Dog::Dog(void)
    : Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& dog)
    : Animal(dog.type)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
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
