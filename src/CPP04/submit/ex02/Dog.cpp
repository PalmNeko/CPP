#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
    : Animal("Dog")
{
    brain = new Brain();
    std::cout << " + Dog" << std::endl;
}

Dog::Dog(const Dog& dog)
    : Animal(dog.type)
{
    brain = new Brain();
    *this = dog;
    std::cout << " @ Copy(Dog)" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << " - Dog(" + this->getType() + ")" << std::endl;
    delete brain;
}

void Dog::makeSound(void) const
{
    std::cout << "Bark" << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
    if (this != &dog)
    {
        this->Animal::operator=(dog);
        delete this->brain;
        this->brain = NULL;
        if (dog.brain != NULL)
            this->brain = new Brain(*dog.brain);
        else
            this->brain = NULL;
        std::cout << " = Dog" << std::endl;
    }
    return *this;
}
