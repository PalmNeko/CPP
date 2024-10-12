#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie(void)
    :name("")
{}

Zombie::Zombie(std::string name)
    :name(name)
{}

Zombie::~Zombie(void)
{
    std::cout << this->name << ": Freeeze!!" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
    return ;
}
