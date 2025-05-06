#include "Dog.hpp"
#include <iostream>

/*
 * special member functions
 */
Dog::Dog(void)
    : Animal("Dog")
{
    std::cout << " + Dog" << std::endl;
}

Dog::Dog(const Dog& dog)
    : Animal(dog.type)
{
    std::cout << " @ Copy(Dog)" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << " - Dog(" + this->getType() + ")" << std::endl;
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
