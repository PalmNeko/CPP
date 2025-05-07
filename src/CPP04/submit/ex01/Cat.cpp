#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat(void)
    : Animal("Cat")
{
    brain = new Brain();
    std::cout << " + Cat" << std::endl;
}

Cat::Cat(const Cat& cat)
    : Animal(cat.type)
{
    brain = new Brain();
    std::cout << " @ Copy(Cat)" << std::endl;
}

Cat::~Cat(void)
{
    delete brain;
    std::cout << " - Cat(" + this->getType() + ")" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Miaow" << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
    if (this != &cat)
    {
        this->Animal::operator=(cat);
        std::cout << " = Cat" << std::endl;
    }
    return *this;
}
