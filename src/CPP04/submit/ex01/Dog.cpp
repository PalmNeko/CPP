#include "Dog.hpp"
#include <iostream>

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

void Dog::makeSound(void) const
{
    std::cout << "Bark" << std::endl;
}

Dog& Dog::operator=(const Dog& cat)
{
    if (this != &cat)
    {
        this->Animal::operator=(cat);
        std::cout << " = Dog" << std::endl;
    }
    return *this;
}
